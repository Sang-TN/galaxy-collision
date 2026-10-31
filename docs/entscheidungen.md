# Entscheidungen

Jede Entscheidung folgt dem Schema **Entscheidung → Alternativen → Begründung**.

---

## E1 – raylib per FetchContent einbinden (M0)

**Entscheidung:** raylib wird über CMake `FetchContent` mit dem festen Git-Tag `5.5` eingebunden.

**Alternativen:**
- Installation über einen Paketmanager (Homebrew auf macOS, apt unter Linux)
- raylib-Quellcode manuell ins Repository kopieren

**Begründung:**
- Reproduzierbarkeit: Auf jedem Rechner wird genau dieselbe Version verwendet.
- Keine manuelle Vorarbeit: CMake lädt raylib beim Konfigurieren selbst herunter.

*Noch zu ergänzen: Warum der feste Tag `5.5` statt des neuesten Stands?*


---

## E2 – Eigene Klasse `Vec3` statt einzelner Zahlen oder raylibs `Vector3` (M1)

**Entscheidung:** Für Positionen, Geschwindigkeiten und Beschleunigungen wird eine eigene Klasse `Vec3` verwendet.

**Alternativen:**
- Keine Klasse, sondern x, y und z jeweils als einzelne Variablen
- Den Typ `Vector3` aus raylib verwenden

**Begründung:**
- Gegen einzelne Variablen: Jede Rechnung müsste dreimal geschrieben werden (für x, y und z). Das ist unübersichtlich und fehleranfällig. Mit `Vec3` sieht der Code fast aus wie die Formel, z. B. `position + geschwindigkeit * dt`.
- Gegen raylibs `Vector3`: Nach der Projektarchitektur ist die Physik unabhängig von der Grafikbibliothek. Die Physik soll ohne raylib funktionieren und testbar sein.

Benötigte Operationen (Herleitung in `theorie.md`, Abschnitte 3 und 4):

| Operation | Art |
|---|---|
| Addition | Vektor + Vektor |
| Subtraktion | Vektor − Vektor |
| Skalarmultiplikation | Vektor · Skalar |
| Division | Vektor / Skalar |
| Betrag | Vektor → Skalar |


---

## E3 – `Vec3` als header-only-Klasse (M1)

**Entscheidung:** Deklaration und Implementierung von `Vec3` stehen gemeinsam in `src/core/vec3.hpp`, ohne eigene `.cpp`-Datei.

**Alternative:**
- Aufteilung in `vec3.hpp` (Deklaration) und `vec3.cpp` (Implementierung)

**Begründung:**
- Die Operatoren sind sehr klein und werden pro Zeitschritt für zehntausende Sterne aufgerufen, also millionenfach pro Sekunde.
- Steht der Funktionsrumpf im Header, kann der Compiler ihn per **Inlining** direkt an die Aufrufstelle kopieren. Der Funktionsaufruf entfällt.
- Bei einer Aufteilung sieht der Compiler beim Übersetzen anderer Dateien nur die Deklaration und kann nicht inlinen (siehe `theorie.md`, Abschnitt 4.6).


---

## E4 – Datentyp `float` für die Komponenten von `Vec3` (M1)

**Entscheidung:** x, y und z werden als `float` gespeichert.

**Alternativen:**
- `int`: scheidet aus, da keine Nachkommastellen möglich sind (z. B. dt = 0,01)
- `double`: doppelte Genauigkeit (ca. 15–16 statt ca. 7 gültige Stellen)

**Begründung:**
- Halber Speicher (4 statt 8 Byte) und damit schneller bei zehntausenden Sternen
- raylib arbeitet intern mit `float`, eine Umwandlung fürs Zeichnen entfällt
- Das geplante Snapshot-Format rechnet mit 4 Byte pro Wert
- Für Stufe 1 (masselose Teststerne) reicht die Genauigkeit voraussichtlich aus

*Zu überprüfen in M4:* Ob sich die Rundungsfehler über viele Zeitschritte in der Energiedrift bemerkbar machen. Gegebenenfalls Vergleichsmessung `float` gegen `double`.


---

## E5 – `class` mit öffentlichen Attributen (M1)
 
**Entscheidung:** `Vec3` wird als `class` geschrieben. Die Attribute x, y und z sind `public`, ohne Getter und Setter.
 
**Alternativen:**
- `private` Attribute mit Gettern und Settern
- `struct` statt `class` (in C++ identisch, nur standardmäßig `public`; übliche Konvention für reine Datentypen)
**Begründung:**
- Kapselung mit `private` schützt eine **Invariante**, also eine Regel, die immer gelten muss (z. B. Kontostand nie negativ). Bei `Vec3` ist jede Kombination von x, y und z gültig. Es gibt nichts zu schützen, Getter und Setter wären nur zusätzlicher Code ohne Nutzen.
- Direkter Zugriff wie `v.x` hält die Formeln im Code kurz und lesbar.
- `class` statt `struct`: Aus dem Unterricht vertraut. Technisch sind beide gleichwertig, da die Sichtbarkeit ausdrücklich mit `public:` festgelegt wird.
**Zusätzlich:** Die Attribute haben den Startwert 0, damit `Vec3 v;` den Nullvektor (0, 0, 0) ergibt statt zufälliger Werte aus dem Speicher.


---
 
## E6 – Keine Prüfung auf Division durch 0 in `operator/` (M1)
 
**Entscheidung:** `operator/` prüft nicht, ob der Skalar 0 ist.
 
**Alternativen:**
- Prüfung in der Methode mit Fehlermeldung oder Ausnahme (Exception)
- Prüfung in der Methode mit Ersatzwert (z. B. Nullvektor zurückgeben)
**Begründung:**
- Bei `float` stürzt eine Division durch 0 nicht ab. Nach dem Standard **IEEE 754** ergibt 1,0 / 0,0 den Wert **inf** (unendlich) und 0,0 / 0,0 den Wert **NaN** (*Not a Number*). Gefährlich ist NaN, weil jede weitere Rechnung damit wieder NaN ergibt.
- Eine Prüfung würde jede der millionenfachen Divisionen pro Sekunde verlangsamen.
- Der kritische Fall wird bereits durch die Gravitationsformel verhindert: Durch das **Softening** ε ist der Nenner (|r|² + ε²)^(3/2) auch bei |r| = 0 nie 0.
- Verantwortlich für gültige Eingaben ist der Aufrufer, nicht der Vektor.


---
 
## E7 – `src` als Include-Verzeichnis (M1)
 
**Entscheidung:** In `CMakeLists.txt` wird `${CMAKE_SOURCE_DIR}/src` per `target_include_directories` als Include-Verzeichnis eingetragen. Header werden mit Modulpfad eingebunden, z. B. `#include "core/vec3.hpp"`.
 
**Alternativen:**
- Relativer Pfad in jeder Quelldatei, z. B. `#include "../src/core/vec3.hpp"`
- Jedes Modul einzeln als Include-Verzeichnis (`src/core`, `src/physics`, …), Einbinden dann nur mit Dateinamen
**Begründung:**
- Zentral an einer Stelle festgelegt: Werden Dateien verschoben, müssen nicht alle `#include`-Zeilen angepasst werden.
- Der Modulpfad im `#include` zeigt sofort, zu welchem Teil der Architektur ein Header gehört (z. B. `core/` oder `physics/`).
- Ein einziger Eintrag reicht für alle späteren Module. Gleichnamige Dateien in verschiedenen Modulen geraten nicht in Konflikt.
**Unterschied `include` und `link`:** `target_include_directories` sagt dem **Compiler**, wo er Header findet. `target_link_libraries` sagt dem **Linker**, welche fertigen Bibliotheken eingebunden werden.


---
 
## E8 – Teilchenspeicher als Struct of Arrays (SoA) (M1)
 
**Entscheidung:** Die Sterne werden als **Struct of Arrays** gespeichert: ein Array mit allen Positionen, eines mit allen Geschwindigkeiten. Ein Stern ist ein Index in diesen Arrays. Eine eigene Klasse besitzt die Arrays und hält sie synchron.
 
**Alternative:**
- **Array of Structs (AoS):** eine Klasse `Stern` mit Position und Geschwindigkeit, alle Sterne in einer Liste
**Begründung (eigene Worte):** SoA lässt mehr Spielraum, falls das Projekt später größer wird als geplant (mehr Sterne, Barnes-Hut, Parallelisierung).
 
**Fachliche Gründe:**
- **Cache-Lokalität:** Der Prozessor lädt Daten in Blöcken (Cache-Lines, meist 64 Byte). Bei SoA liegen z. B. alle Positionen direkt hintereinander, ein geladener Block enthält nur benötigte Daten. Bei AoS lädt er auch Daten mit, die die aktuelle Schleife nicht braucht.
- **Zeichnen:** raylib zeichnet viele Punkte am effizientesten, wenn alle Positionen zusammenhängend im Speicher liegen.
- **Barnes-Hut (M5):** Der Aufbau des Octrees benötigt nur die Positionen.
**Nachteile und Gegenmaßnahme:**
- Weniger intuitiv, ein Stern ist kein eigenes Objekt mehr, die Zusammengehörigkeit ergibt sich nur über den Index.
- Die Arrays müssen immer gleich lang und gleich sortiert sein.
- Gegenmaßnahme: Die Kapselung liegt eine Ebene höher. Eine Klasse für den ganzen Teilchenspeicher besitzt die Arrays und ist als einzige dafür zuständig, dass sie synchron bleiben.
*Hinweis:* Bei nur Position und Geschwindigkeit (24 Byte pro Stern) ist der Geschwindigkeitsvorteil in Stufe 1 voraussichtlich klein. Eine Messung AoS gegen SoA wäre eine mögliche Ergänzung für `tests.md`.


---

## E9 – Teilchenspeicher: `private` Vektoren (M1)
 
**Entscheidung:** Die Vektoren `positionen`, `geschwindigkeiten` und `beschleunigungen` sind `private`. Neue Sterne kommen nur über `hinzufuegen` hinein. Die Bezeichner sind deutsch.
 
**Alternativen:**
- `public` Vektoren wie bei `Vec3`
- Englische Bezeichner
**Begründung:**
- Anders als bei `Vec3` gibt es hier eine **Invariante**: Alle drei Vektoren müssen immer gleich lang und gleich sortiert sein. Wären sie `public`, könnte jemand von außen z. B. nur `positionen.push_back(...)` aufrufen. Dann gehörten Position und Geschwindigkeit eines Index nicht mehr zum selben Stern, ohne Fehlermeldung.
- Mit `private` gibt es genau eine Stelle (`hinzufuegen`), die alle drei Vektoren gemeinsam verändert.


---
 
## E10 – Zugriff auf den Teilchenspeicher über `std::span` (M1)
 
**Entscheidung:** Der Teilchenspeicher gibt seine Vektoren nicht direkt heraus. Lesender Zugriff erfolgt über `const`-Referenzen bzw. einen `span` auf `const Vec3`. Ändernder Zugriff (Physik) erfolgt über `std::span<Vec3>`.
 
**Alternativen:**
- Getter mit Kopie (`std::vector<Vec3>`)
- Getter mit veränderbarer Referenz (`std::vector<Vec3>&`)
- Zugriff pro Element über einen Index, z. B. `position(i)`
**Begründung:**
- Eine Kopie wäre bei zehntausenden Sternen teuer und Änderungen kämen nicht im Original an.
- Eine veränderbare Referenz erlaubt `push_back` von außen und umgeht damit die Invariante aus E9.
- `std::span` erlaubt genau das Benötigte: Werte ändern, aber nicht die Größe. Es kopiert nichts.
- Bezug zu E8 (SoA): Der `span` liefert alle Positionen als zusammenhängenden Bereich, gut für Cache und Zeichnen.
- `std::span` ist Teil von C++20, das im Projekt ohnehin verwendet wird.


---
 
## E11 – Zufällige Punktwolke mit festem Seed (M1)
 
**Entscheidung:** Startpositionen für M1 erzeugt die freie Funktion `zufaelligePunkte` in `src/setup/zufall.hpp` mit `std::mt19937` und `std::uniform_real_distribution`. Der Seed wird als Parameter übergeben, im Test ist er fest (`42`).
 
**Alternativen:**
- `rand()` aus C
- Seed aus der Uhrzeit oder `std::random_device` (bei jedem Start andere Werte)
- Eine Klasse statt einer freien Funktion
**Begründung:**
- `<random>` ist der moderne C++-Standard, `rand()` gilt als veraltet und hat schlechte Qualität.
- Ein fester Seed macht Läufe **reproduzierbar**: Fehler lassen sich wiederholen, Ergebnisse vergleichen und Tests liefern immer dasselbe Ergebnis.
- Die Funktion hat keinen eigenen Zustand, den sie über mehrere Aufrufe behalten müsste. Eine freie Funktion reicht, eine Klasse wäre Overkill.
- Startbedingungen liegen laut Architektur in `src/setup/`.
**Einschränkung:** Die Umrechnung durch `uniform_real_distribution` unterscheidet sich zwischen Standardbibliotheken. Reproduzierbar ist es auf demselben System (siehe `theorie.md` 6.2).

---

## E12 – Umwandlung `Vec3` → `Vector3` in `src/render/` (M1)

**Entscheidung:** raylib zeichnet nur mit seinem eigenen Typ `Vector3`. Die Umwandlung übernimmt die freie Funktion `zuVector3(const Vec3 &)` in `src/render/umwandlung.hpp`. `src/core/vec3.hpp` bindet `raylib.h` nicht ein.

**Alternativen:**
- Umwandlung als Methode oder Funktion direkt in `vec3.hpp`
- raylibs `Vector3` überall statt eines eigenen `Vec3` verwenden (verworfen in E2)
- Umwandlung direkt in `viewer.cpp` ausschreiben
**Begründung:**
- **Abhängigkeitsrichtung:** `render/` darf `core/` kennen, aber nicht umgekehrt. Würde `vec3.hpp` `raylib.h` einbinden, hinge jede Datei, die `Vec3` benutzt, an der Grafikbibliothek. Das gilt auch für Physik, Tests und die Headless-Simulation `sim.cpp`, die nie etwas zeichnen.
- **Geringe Kopplung:** Physik und Datenhaltung bleiben ohne raylib baubar und testbar, z. B. in Codespaces ohne Fenster. Ein Wechsel der Grafikbibliothek beträfe nur `render/`.
- Eine eigene Funktion statt ausgeschriebener Umwandlung in `viewer.cpp` hält die Stelle an einem Ort und ist wiederverwendbar.
- Parameter als `const Vec3 &`: nur lesen, keine Kopie. Rückgabe von `Vector3` per Aggregat-Initialisierung `{ }`, da `Vector3` ein C-`struct` ohne Konstruktor ist.
- `inline`, weil die Funktion in einem Header definiert ist und sonst bei mehrfachem Einbinden gegen die One-Definition-Rule verstoßen würde.


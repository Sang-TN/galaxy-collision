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
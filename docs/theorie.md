# Theoretische Grundlagen

## 1 Ziel der Simulation und von M1

Die Simulation soll am Ende zehntausende Sterne zeigen, die sich im Raum bewegen. Dafür muss für jeden Stern zu jedem Zeitpunkt bekannt sein:

1. **Position:** wo sich der Stern befindet,
2. **Geschwindigkeit:** wie schnell und in welche Richtung er sich bewegt,
3. **Beschleunigung:** wie stark und in welche Richtung er gerade gezogen wird.

Meilenstein M1 behandelt nur den ersten Punkt: Punkte im Raum speichern und anzeigen. Physik kommt erst ab M2 hinzu.

## 2 Vektoren und Skalare

### 2.1 Vektor

Ein Vektor im dreidimensionalen Raum besteht aus drei Zahlen, den **Komponenten** x, y und z. Er lässt sich auf zwei Arten deuten:

- **als Ort:** z. B. (3, 2, 5) = „3 nach rechts, 2 nach oben, 5 nach hinten“
- **als Pfeil:** mit einer Richtung und einer Länge

Position, Geschwindigkeit und Beschleunigung sind Vektoren. Die Geschwindigkeit (1, 0, 0) bedeutet zum Beispiel: Der Stern bewegt sich nach rechts.

### 2.2 Skalar

Eine normale Zahl ohne Richtung heißt Skalar. Beispiele in der Simulation: Zeit, Masse, die Gravitationskonstante G.

Skalar ist kein Punkt. Ein Punkt im Raum braucht drei Zahlen (x, y, z) und ist damit ein Vektor. Ein Skalar ist nur eine einzige Zahl.

Ein Abstand hat keine Richtung. „Der Bäcker ist 500 m entfernt“ sagt, wie weit, aber nicht, wohin. Deshalb ist der Betrag eines Vektors (siehe 3.5) ein Skalar: Aus dem Pfeil (3, 4, 0) mit Richtung und Länge wird nur noch die Länge 5. Die Richtung geht verloren.

Skalar ist nicht dasselbe wie Konstante. Skalar heißt: eine einzelne Zahl ohne Richtung. Konstante heißt: ein Wert, der sich nie ändert. Das sind zwei unabhängige Eigenschaften.

## 3 Rechenoperationen mit Vektoren

### 3.1 Addition (Vektor + Vektor)

Zwei Vektoren werden **komponentenweise** addiert: x mit x, y mit y, z mit z.

(a₁, a₂, a₃) + (b₁, b₂, b₃) = (a₁ + b₁, a₂ + b₂, a₃ + b₃)

### 3.2 Skalarmultiplikation (Vektor × Skalar)

Jede Komponente wird mit derselben Zahl multipliziert.

(a₁, a₂, a₃) · k = (a₁ · k, a₂ · k, a₃ · k)

### 3.3 Beispiel: Bewegung eines Sterns

Ein Stern befindet sich bei (2, 0, 0) und bewegt sich mit der Geschwindigkeit (0, 1, 0), also nach oben. Position nach 1 Sekunde:

neue Position = alte Position + Geschwindigkeit · Zeit
= (2, 0, 0) + (0, 1, 0) · 1
= (2, 1, 0)

Hier werden beide Operationen benutzt: erst die Skalarmultiplikation (Geschwindigkeit · Zeit), dann die Addition (Position + Ergebnis). Genau solche Rechnungen führt die Simulation millionenfach aus.

### 3.4 Subtraktion und Abstandsvektor

Für die Gravitation muss ein Stern wissen, in welche Richtung und wie weit das Galaxienzentrum entfernt ist. Dazu wird ein Vektor vom anderen subtrahiert, ebenfalls komponentenweise.

**Regel: Ziel minus Start.**

Beispiel: Zentrum bei (1, 1, 0), Stern bei (4, 5, 0).

Pfeil vom Zentrum zum Stern = Stern − Zentrum
= (4, 5, 0) − (1, 1, 0)
= (3, 4, 0)

Dieser Pfeil heißt **Abstandsvektor** (auch Verbindungsvektor), in der Gravitationsformel **r**.

**Die Reihenfolge ist entscheidend.** Zentrum − Stern ergibt (−3, −4, 0): gleich lang, aber genau entgegengesetzt. In der Gravitation entscheidet das darüber, ob der Stern zum Zentrum hin angezogen oder fälschlich weggestoßen wird. Das ist einer der häufigsten Fehler.

### 3.5 Betrag (Länge) eines Vektors
 
Der **Betrag** |r| ist die Länge eines Vektors, also der tatsächliche Abstand zwischen zwei Punkten. Er wird mit dem **Satz des Pythagoras** berechnet.
 
**In 2D** (z = 0): Die Komponenten x und y sind die beiden Seiten (Katheten), die den rechten Winkel bilden. Die gesuchte Länge ist die längste Seite (Hypotenuse).
 
c² = a² + b²  ⇒  c = √(a² + b²)
 
Beispiel: |(3, 4, 0)| = √(3² + 4²) = √25 = **5**
 
Die Wurzel steht über der **ganzen Summe der Quadrate**. Ein typischer Fehler ist, einfach 3 + 4 = 7 zu rechnen. Das wäre der Weg „um die Ecke“, nicht die gerade Verbindung.
 
**In 3D:** Der Satz des Pythagoras wird zweimal angewendet.
 
1. Länge in der x-y-Ebene („am Boden“): √(x² + y²)
2. Diese Länge und z bilden ein neues rechtwinkliges Dreieck, das senkrecht nach oben steht. Darauf wird Pythagoras erneut angewendet.
Quadrat und Wurzel heben sich dabei auf, und es ergibt sich:
 
**|r| = √(x² + y² + z²)**
 
Beispiel: |(3, 4, 12)|
- über zwei Schritte: √(5² + 12²) = √169 = **13**
- direkt: √(3² + 4² + 12²) = √(9 + 16 + 144) = √169 = **13**
c ist dabei kein fester Wert, sondern immer der Name der gesuchten Hypotenuse. Im zweiten Schritt ist die 12 eine Kathete, keine Hypotenuse.
 
**Wichtig:** Der Betrag macht aus einem Vektor einen **Skalar**. Bei Addition, Subtraktion und Skalarmultiplikation kommt dagegen wieder ein Vektor heraus.

### 3.6 Division durch einen Skalar (Vektor / Skalar)
 
Jede Komponente wird durch dieselbe Zahl geteilt.
 
(a₁, a₂, a₃) / k = (a₁ / k, a₂ / k, a₃ / k)
 
Beispiel: (6, 8, 0) / 2 = (3, 4, 0)
 
Mathematisch ist das dasselbe wie eine Skalarmultiplikation mit 1/k. Als eigene Operation ist es aber praktisch, weil Formeln oft als Bruch geschrieben werden.
 
### 3.7 Anwendung: die Gravitationsformel
 
```
            G · M · r
a  =  ─────────────────────
       (|r|² + ε²)^(3/2)
```
 
| Teil der Formel | Operation | Ergebnis |
|---|---|---|
| r = Stern − Zentrum | Subtraktion (3.4) | Vektor |
| \|r\| | Betrag (3.5) | Skalar |
| \|r\|² + ε² | normale Zahlenaddition | Skalar |
| G · M · r | Skalarmultiplikation (3.2) | Vektor |
| Zähler / Nenner | Division durch Skalar (3.6) | Vektor |
 
Die Addition im Nenner ist **keine** Vektoraddition, denn |r|² ist bereits eine Zahl. Das Ergebnis a ist ein Vektor: die Beschleunigung, die auf den Stern wirkt. G, M und ε werden in M2 erklärt.


## 4 Umsetzung in C++: Operatorüberladung

### 4.1 Problem

Für eingebaute Datentypen wie `int` oder `float` weiß C++, was `+` bedeutet. Für eine eigene Klasse wie `Vec3` weiß der Compiler das nicht. Der Ausdruck `position + geschwindigkeit` erzeugt ohne weitere Angaben einen Fehler.

### 4.2 Lösung

Mit **Operatorüberladung** (engl. *operator overloading*) wird festgelegt, was ein Operator für eine eigene Klasse bedeutet. Ein Operator ist in C++ eine Funktion mit besonderem Namen. Der Compiler übersetzt

`a + b`  →  sinngemäß `a.operator+(b)`

`operator+` ist also eine normale Methode, die mit dem Zeichen `+` aufgerufen werden kann.

Das Objekt, auf dem die Methode aufgerufen wird (bei `a + b` ist das `a`), heißt in C++ **`this`**. Es ist eine versteckte zusätzliche Eingabe.

### 4.3 Pseudocode

**Addition:**

```
FUNKTION operator+ (anderer Vektor)
    neuer Vektor mit:
        x = mein x + anderes x
        y = mein y + anderes y
        z = mein z + anderes z
    gib neuen Vektor zurück
```

**Skalarmultiplikation:**

```
FUNKTION operator* (Skalar)
    neuer Vektor mit:
        x = mein x · Skalar
        y = mein y · Skalar
        z = mein z · Skalar
    gib neuen Vektor zurück
```

### 4.4 Ein- und Ausgaben aller Operationen

| Operation | Methode | Eingabe (außer `this`) | Rückgabe |
|---|---|---|---|
| Addition | `operator+` | ein `Vec3` | neues `Vec3` |
| Subtraktion | `operator-` | ein `Vec3` | neues `Vec3` |
| Skalarmultiplikation | `operator*` | eine Zahl (`float`) | neues `Vec3` |
| Division | `operator/` | eine Zahl (`float`) | neues `Vec3` |
| Betrag | `length()` | keine | eine Zahl (`float`) |

Eine Funktion kann in C++ nur **einen** Wert zurückgeben. Weil x, y und z in einem Objekt gebündelt sind, kann trotzdem ein ganzer Vektor zurückgegeben werden.

### 4.5 Die Ausgangsvektoren bleiben unverändert

Die Operatoren `+`, `-`, `*` und `/` verändern weder `this` noch die Eingabe, sondern erzeugen ein **neues** Objekt, genau wie bei `3 + 4`, wo 3 und 4 ebenfalls unverändert bleiben.

Beispiel, warum das wichtig ist: In `position + geschwindigkeit * dt` würde ein `operator*`, der `this` verändert, die Geschwindigkeit selbst mit dt multiplizieren und überschreiben. Bei dt = 0,01 wäre der Stern nach jedem Schritt hundertmal langsamer und bliebe fast sofort stehen.

### 4.6 Header und Quelldatei, Inlining
 
- **Header (`.hpp`):** enthält die Deklaration, also die Schnittstelle der Klasse. Er sagt, *was* die Klasse kann. Andere Dateien binden ihn mit `#include` ein, damit der Compiler die Klasse kennt.
- **Quelldatei (`.cpp`):** enthält die Implementierung, also *wie* die Methoden arbeiten.
- Jede `.cpp` wird einzeln übersetzt (eine **Übersetzungseinheit**). Der **Linker** verbindet am Ende alle Teile zu einem Programm.
**Inlining:** Sieht der Compiler den Rumpf einer kleinen Funktion, kann er ihn direkt an die Aufrufstelle kopieren. Dadurch entfällt der Funktionsaufruf (Sprung hin und zurück). Das ist nur möglich, wenn der Rumpf in derselben Übersetzungseinheit sichtbar ist, also im Header steht.
 
Für `Vec3`, dessen Operatoren millionenfach pro Sekunde aufgerufen werden, wird deshalb die **header-only**-Variante gewählt: Deklaration und Implementierung stehen gemeinsam in `src/core/vec3.hpp` (Begründung in `docs/entscheidungen.md`).

### 4.7 Startwerte der Attribute (Nullvektor)
 
Eine `float`-Variable ohne Startwert wird in C++ nicht automatisch auf 0 gesetzt. Sie enthält, was zufällig vorher an dieser Stelle im Speicher stand. Deshalb bekommen x, y und z den Startwert 0. `Vec3 v;` ergibt so den **Nullvektor** (0, 0, 0).
 
- **Nullvektor:** Addiert man ihn zu einem Vektor, ändert sich nichts: v + (0, 0, 0) = v
- **Ursprung:** Als Ort gedeutet ist (0, 0, 0) der Mittelpunkt des Koordinatensystems.
**Typischer Fehler:** In `float x, y, z = 0;` gehört `= 0` nur zu `z`. x und y bleiben uninitialisiert. Richtig ist `float x = 0, y = 0, z = 0;`. Der Compiler meldet diesen Fehler nicht.
 
### 4.8 Referenzen und `const`
 
**Wertübergabe** (`Vec3 other`): Die Funktion bekommt eine **Kopie** des Arguments.
 
**Referenzübergabe** (`Vec3& other`): Die Funktion arbeitet direkt mit dem **Original**, es wird nichts kopiert. Die Referenz ist nur ein zweiter Name für dasselbe Objekt.
 
**`const` beim Parameter** (`const Vec3& other`): Das Original darf in der Funktion nicht verändert werden. Zusammen bedeutet das: nicht kopieren, aber auch nicht verändern. Das ist die übliche Konvention für Klassen-Parameter. Bei `Vec3` mit nur 12 Byte wäre eine Kopie ebenfalls billig.
 
**Einfache Zahlen** (`float skalar`) werden als Wert übergeben, weil eine 4-Byte-Kopie billiger ist als eine Referenz.
 
**`const` hinter der Parameterliste** (`... ) const`): macht die Methode zu einer **konstanten Methode**. Sie darf `this`, also das eigene Objekt, nicht verändern.
 
Bei `a + b` gilt damit:
- `b` (= `other`) ist durch `const Vec3&` geschützt,
- `a` (= `this`) ist durch das `const` hinter der `)` geschützt,
- das Ergebnis ist ein **neues** `Vec3`.
Abgrenzung zu ähnlichen Schlüsselwörtern:
- **`final`** verbietet, dass eine Unterklasse die Methode überschreibt (Vererbung).
- **`static`** macht eine Methode unabhängig von einem Objekt, sie hat dann kein `this`.
### 4.9 Endlose Rekursion
 
**Rekursion** bedeutet, dass eine Funktion sich selbst aufruft. Ohne Abbruchbedingung ruft sie sich endlos auf, bis der Speicher für Funktionsaufrufe (der **Stack**) voll ist und das Programm mit einem **Stack Overflow** abstürzt.
 
**Typischer Fehler in `operator+`:**
 
```
return Vec3(x, y, z) + Vec3(other.x, other.y, other.z);
```
 
Das `+` steht zwischen zwei `Vec3` und ruft damit wieder `operator+` auf, also sich selbst. Richtig ist, die **einzelnen Zahlen** zu addieren (`float + float`), denn dafür kennt C++ das `+` bereits:
 
```
return Vec3(x + other.x, y + other.y, z + other.z);
```
 
### 4.10 Gleitkommazahlen: Division durch 0 (IEEE 754)
 
Bei `int` führt eine Division durch 0 zum Absturz. Bei `float` legt der Standard **IEEE 754** fest:
 
- 1,0 / 0,0 = **inf** (unendlich)
- 0,0 / 0,0 = **NaN** (*Not a Number*)
Das Programm läuft weiter. Gefährlich ist NaN, weil jede weitere Rechnung damit wieder NaN ergibt. Ein einzelner fehlerhafter Stern verschwindet dann ohne Fehlermeldung. In der Gravitationsformel verhindert das **Softening** ε diesen Fall (siehe `entscheidungen.md`, E6).
 
### 4.11 Die Wurzel in C++
 
Die Quadratwurzel stellt die Standardbibliothek `<cmath>` als **`std::sqrt`** bereit (*square root*). `std::` ist der **Namensraum** (*namespace*) der C++-Standardbibliothek. Fehlt `#include <cmath>`, meldet der Editor, dass `std` kein Element `sqrt` hat.
 
Quadrate werden als `x * x` statt mit einer Potenzfunktion berechnet, weil eine einfache Multiplikation schneller ist.
 
`length()` gibt einen `float` zurück, keinen `Vec3`, denn der Betrag ist ein Skalar (siehe 2.2 und 3.5).

## 5 Speicherung vieler Teilchen
 
### 5.1 Array of Structs (AoS) und Struct of Arrays (SoA)
 
**Array of Structs (AoS):** Jeder Stern ist ein Objekt, alle Objekte stehen in einer Liste. Die Daten eines Sterns liegen im Speicher nebeneinander.
 
```
sterne = [ Stern{pos, vel}, Stern{pos, vel}, Stern{pos, vel}, ... ]
```
 
**Struct of Arrays (SoA):** Je Eigenschaft gibt es ein eigenes Array. Ein Stern ist nur noch ein **Index**.
 
```
positionen      = [ pos0, pos1, pos2, ... ]
geschwindigkeit = [ vel0, vel1, vel2, ... ]
```
 
Stern Nummer 5 ist `positionen[5]` und `geschwindigkeit[5]`.
 
| | AoS | SoA |
|---|---|---|
| Verständlichkeit | intuitiv, objektorientiert | weniger intuitiv |
| Kapselung | pro Stern | nur über eine übergeordnete Klasse |
| Fehlerrisiko | gering | Arrays müssen gleich lang und gleich sortiert bleiben |
| Cache-Lokalität | schlechter | besser |
 
### 5.2 Der Cache
 
Der Prozessor holt Daten nicht einzeln aus dem Arbeitsspeicher, weil das zu langsam wäre. Er lädt immer einen ganzen Block nebeneinanderliegender Daten (eine **Cache-Line**, meist 64 Byte) in seinen schnellen Zwischenspeicher, den **Cache**. Das lohnt sich nur, wenn in diesem Block auch das steckt, was als Nächstes gebraucht wird.
 
Beispiel: Die Schleife „für alle Sterne: Position = Position + Geschwindigkeit · dt“ braucht keine Farbe, Masse oder Herkunft.
- Bei **AoS** liegen diese Daten zwischen den Positionen. Ein geladener Block enthält viel Unnötiges.
- Bei **SoA** liegen alle Positionen direkt hintereinander. Ein geladener Block enthält nur benötigte Daten.
Diese Eigenschaft heißt **Cache-Lokalität** (*cache locality*). Die Entscheidung für das Projekt ist in `entscheidungen.md`, E8 begründet.

### 5.3 Zugriff auf private Daten: Kopie, Referenz und `std::span`
 
Sind die Vektoren `private`, brauchen andere Programmteile einen kontrollierten Zugriff. Die Darstellung muss die Positionen **lesen**, die Physik muss sie **ändern**. Entscheidend ist, was ein Getter zurückgibt:
 
| Rückgabe | Lesen | Elemente ändern | Größe ändern | Problem |
|---|---|---|---|---|
| `std::vector<Vec3>` (Kopie) | ✔ | nur in der Kopie | nur in der Kopie | Alle Elemente werden kopiert, Änderungen erreichen das Original nicht |
| `const std::vector<Vec3>&` | ✔ | ✘ | ✘ | Die Physik kann nichts ändern |
| `std::vector<Vec3>&` | ✔ | ✔ | ✔ | `push_back` von außen möglich, die Invariante ist umgangen |
| `std::span<Vec3>` | ✔ | ✔ | ✘ | – |
 
**`std::span`** (C++20, `<span>`) ist ein **Sichtfenster** auf zusammenhängend gespeicherte Daten:
- Elemente können gelesen und geändert werden, z. B. `pos[5] = …`.
- Elemente können nicht hinzugefügt oder entfernt werden, `span` hat kein `push_back`.
- Es wird nichts kopiert. Eine Änderung über den `span` ändert direkt das Original im `std::vector`, ähnlich wie eine Referenz, nur für einen ganzen Bereich.
`std::span` funktioniert, weil `std::vector` seine Elemente zusammenhängend speichert.

### 5.4 Objekte anlegen: benannt, temporär und eine Falle

**Benanntes Objekt:** `Teilchenspeicher speicher;` legt ein Objekt mit Namen an. Es existiert bis zum Ende des umgebenden Blocks `{ }` und kann in mehreren Zeilen benutzt werden.

**Temporäres Objekt:** `Teilchenspeicher()` erzeugt ein namenloses Objekt, das am Ende der Zeile wieder gelöscht wird. Typischer Fehler:

```
Teilchenspeicher().hinzufuegen(v, v1);            // Objekt 1: Stern hinein, danach gelöscht
std::cout << Teilchenspeicher().anzahl();         // Objekt 2: neu und leer → Ausgabe 0
```

Richtig ist ein benanntes Objekt, das in beiden Zeilen verwendet wird.

**Most Vexing Parse:** `Vec3 v2();` erzeugt **keinen** Nullvektor. C++ liest die Zeile als Deklaration einer Funktion `v2`, die ein `Vec3` zurückgibt. Ein Objekt mit Standardkonstruktor wird **ohne** Klammern angelegt: `Vec3 v2;`

### 5.5 `std::vector`: Elemente anhängen und zählen

- **`liste.push_back(element)`** hängt ein Element hinten an. Vor dem Punkt steht die Liste, **an die** angehängt wird, in den Klammern das Element, **das** angehängt wird.
- **`liste.size()`** gibt die Anzahl der Elemente zurück, als `std::size_t`.
- **`std::size_t`** (definiert in `<cstddef>`) ist ein **vorzeichenloser** ganzzahliger Typ (*unsigned*), der nie negativ wird. Er ist der übliche Typ für Größen und Anzahlen.

**Regel für Includes:** Was eine Datei benutzt, bindet sie selbst ein, auch wenn es zufällig schon über einen anderen Header mitkommt.

Im Teilchenspeicher hängt `hinzufuegen` an **alle drei** Listen genau ein Element an. Deshalb reicht in `anzahl()` die Abfrage **einer** Liste.

### 5.6 Getter mit und ohne `const` (Überladung)

Zwei Methoden dürfen denselben Namen haben, wenn sie sich unterscheiden. Das nennt man **Überladung**. Beim Teilchenspeicher unterscheiden sich die beiden `positionen()` nur durch das `const` hinter der Klammer:

| Methode | Rückgabe | Zweck |
|---|---|---|
| `positionen()` | `std::span<Vec3>` | Werte ändern (Physik) |
| `positionen() const` | `std::span<const Vec3>` | nur lesen (Darstellung) |

Der Compiler wählt automatisch: Ist das Objekt `const`, wird die lesende Variante benutzt.

Ein Unterschied **nur im Rückgabetyp** reicht nicht, weil der Compiler beim Aufruf `speicher.positionen()` den Rückgabetyp nicht sieht. Eine `const`-Methode darf außerdem keinen `span<Vec3>` herausgeben, sonst könnte der Aufrufer das Objekt darüber verändern und das Versprechen von `const` wäre gebrochen.

## 6 Zufällige Startpositionen

### 6.1 Pseudozufall und Seed

Ein Computer erzeugt keinen echten Zufall. Ein **Pseudozufallszahlengenerator** berechnet aus einer Startzahl, dem **Seed**, eine Zahlenfolge, die zufällig aussieht. **Gleicher Seed ergibt dieselbe Folge.**

Das sorgt für **Reproduzierbarkeit**:
- **Fehlersuche:** Ein auffälliger Lauf lässt sich beliebig oft identisch wiederholen.
- **Vergleich:** Nach einer Codeänderung liegen Unterschiede am Code, nicht an anderen Startpositionen.
- **Tests:** Ein Test liefert immer dasselbe Ergebnis.

### 6.2 Zufall in C++ (`<random>`)

| Baustein | Aufgabe | im Projekt |
|---|---|---|
| Generator | erzeugt aus dem Seed rohe Zufallszahlen | `std::mt19937` (Mersenne Twister) |
| Seed | Startzahl | z. B. `42` |
| Verteilung | formt die Zahlen in den gewünschten Bereich | `std::uniform_real_distribution<float>(-radius, radius)` |

Jeder Aufruf `verteilung(generator)` liefert eine neue Zahl. Die alte C-Funktion `rand()` gilt als veraltet.

**Einschränkung:** `std::mt19937` ist im Standard exakt festgelegt. Wie `uniform_real_distribution` die Rohzahlen umrechnet, darf jede Standardbibliothek selbst bestimmen. Unter Linux (libstdc++) und macOS (libc++) können deshalb trotz gleichem Seed andere Zahlen entstehen. Reproduzierbar ist es also auf **demselben System**.

### 6.3 Reihenfolge der Auswertung von Argumenten

In C++ ist **nicht festgelegt**, in welcher Reihenfolge die Argumente eines Funktionsaufrufs ausgewertet werden. Bei

```
Vec3(verteilung(generator), verteilung(generator), verteilung(generator))
```

kann ein Compiler von links nach rechts, ein anderer von rechts nach links auswerten. Dann wären x und z vertauscht. Deshalb wird jede Zahl in einer **eigenen Anweisung** erzeugt, denn zwischen Anweisungen gilt immer die Reihenfolge von oben nach unten.

### 6.4 Freie Funktionen im Header: `inline`

Eine **freie Funktion** (nicht in einer Klasse), die in einem Header definiert wird, entsteht in jeder `.cpp`-Datei, die den Header einbindet. Der Linker findet dann mehrere gleichnamige Funktionen und bricht ab. **`inline`** erlaubt diese Mehrfachdefinition ausdrücklich. Methoden, die innerhalb einer Klasse definiert werden, sind automatisch `inline`.

### 6.5 Groß- und Kleinschreibung von Dateinamen

macOS ignoriert Groß- und Kleinschreibung in Dateinamen meist, Linux nicht. `#include "core/Teilchenspeicher.hpp"` findet unter Linux die Datei `teilchenspeicher.hpp` nicht. Konvention im Projekt: **Klassennamen groß** (`Teilchenspeicher`), **Dateinamen klein** (`teilchenspeicher.hpp`).

### 6.6 Würfel statt Kugel

`zufaelligePunkte` zieht x, y und z **unabhängig voneinander** gleichverteilt aus [−r, r]. Damit füllen die Punkte einen **Würfel** mit Kantenlänge 2r, keine Kugel. Ein Punkt wie (0,9; 0,9; 0,9) hat den Abstand √(3 · 0,9²) ≈ 1,56 vom Ursprung und läge außerhalb einer Kugel mit Radius 1.

Eine Kugel erhält man mit der **Verwerfungsmethode** (*rejection sampling*): Punkt im Würfel ziehen, Betrag berechnen, Punkte mit Betrag > r verwerfen und neu ziehen. Für M1 reicht der Würfel, ab M2 liegen die Sterne auf einer Scheibe.

## 7 Darstellung in 3D mit raylib

### 7.1 Game Loop und EVA-Prinzip

Ein Echtzeitprogramm erzeugt in einer Schleife, der **Game Loop**, fortlaufend neue Einzelbilder (**Frames**), vergleichbar mit einem Daumenkino. Jeder Durchlauf folgt dem **EVA-Prinzip**:

1. **Eingabe und Verarbeitung:** Maus und Tastatur lesen, Kamera bewegen, später einen Physik-Schritt rechnen.
2. **Ausgabe:** Bild löschen (`ClearBackground`) und neu zeichnen, zwischen `BeginDrawing` und `EndDrawing`.

Steht die Verarbeitung vor der Ausgabe, zeigt jedes Bild den aktuellen Zustand. Andernfalls hinkt das Bild einen Frame hinterher. Die Trennung hält außerdem Rechnen und Zeichnen auseinander, passend zur Architektur des Projekts.

`SetTargetFPS(60)` begrenzt die Bildrate auf 60 Bilder pro Sekunde (*frames per second*). Das Programm läuft so auf jedem Rechner gleich schnell und belastet den Prozessor nicht unnötig.

### 7.2 Kamera und Projektion

Der Bildschirm ist zweidimensional, die Punkte liegen im dreidimensionalen Raum. Die **Kamera** ist der virtuelle Beobachter, aus dessen Sicht gezeichnet wird. Die Umrechnung von 3D-Koordinaten auf 2D-Bildschirmpositionen heißt **Projektion**.

| Feld von `Camera3D` | Bedeutung | im Projekt |
|---|---|---|
| `position` | Standort der Kamera | (3, 2, 3), schräg oberhalb und außerhalb der Wolke |
| `target` | Punkt, auf den die Kamera blickt | Ursprung (0, 0, 0) |
| `up` | Richtungsvektor, der im Bild nach oben zeigt (Drehung um die Blickachse) | (0, 1, 0) |
| `fovy` | vertikales Sichtfeld (*field of view*) in Grad | 45° |
| `projection` | Art der Projektion | perspektivisch |

Bei der **perspektivischen Projektion** erscheinen entfernte Objekte kleiner, wie beim menschlichen Auge. Bei der **orthografischen Projektion** bleibt die Größe unabhängig von der Entfernung, was für technische Zeichnungen üblich ist.

`BeginMode3D(kamera)` schaltet in den 3D-Modus: Alle folgenden Zeichenbefehle werden als 3D-Koordinaten verstanden und über die Kamera projiziert. `EndMode3D()` schaltet zurück in den 2D-Modus, z. B. für Text.

### 7.3 Kopie, Referenz und Zeiger beim Funktionsaufruf

| Funktion | Parameter | Warum |
|---|---|---|
| `BeginMode3D(Camera3D camera)` | Kopie | liest die Kamera nur |
| `UpdateCamera(Camera *camera, int mode)` | Zeiger | **verändert** die Kamera; eine Änderung an einer Kopie ginge nach dem Aufruf verloren |

Ein **Zeiger** (*pointer*) enthält die **Adresse** einer Variablen im Speicher. Über ihn kann eine Funktion das Original verändern. Die Adresse erhält man mit dem **Adressoperator** `&`, also `UpdateCamera(&kamera, ...)`. raylib ist in C geschrieben, und C kennt keine Referenzen, deshalb verwendet raylib Zeiger, wo in C++ eine Referenz üblich wäre.

Wichtig ist der Unterschied zwischen **Deklaration** und **Aufruf**: `void BeginMode3D(Camera3D camera);` beschreibt nur, welche Parameter die Funktion erwartet. Aufgerufen wird sie mit einem konkreten Wert, ohne Rückgabetyp und ohne Parametertyp: `BeginMode3D(kamera);`.

### 7.4 Aggregat-Initialisierung

`Camera3D` und `Vector3` sind in raylib einfache C-`struct`s **ohne Konstruktor**, sogenannte **Aggregate**. Sie werden mit geschweiften Klammern befüllt. Die Werte werden dabei der Reihe nach den Feldern zugeordnet, deshalb muss die Reihenfolge der Deklaration in `raylib.h` entsprechen:

```
Vector3{ x, y, z }
Camera3D{ position, target, up, fovy, projection }
```

### 7.5 Bereichsbasierte for-Schleife

Die **bereichsbasierte for-Schleife** (*range-based for loop*) durchläuft alle Elemente eines Bereichs, ähnlich wie `for x in liste` in Python:

```
for (const Vec3 &p : speicher.positionen())
```

- `speicher.positionen()` liefert den Bereich (ein `std::span`).
- `p` ist in jedem Durchlauf das aktuelle Element.
- `const Vec3 &` bedeutet: Referenz auf das Original, also **keine Kopie**, und **nur lesend**, der Compiler verhindert Änderungen.

Faustregel: nur lesen → `const T &`; ändern → `T &`; kleine Typen wie `int` oder `float` → Kopie.

### 7.6 Trennung von Physik und Darstellung (Kopplung)

raylib zeichnet nur mit seinem eigenen Typ `Vector3`. Die Umwandlung `zuVector3` liegt in `src/render/`, nicht in `src/core/`. Die **Abhängigkeitsrichtung** ist damit festgelegt: `render/` kennt `core/`, aber `core/` kennt weder `render/` noch raylib.

Würde `vec3.hpp` `raylib.h` einbinden, wären alle Teile, die `Vec3` benutzen (Physik, Tests, Headless-Simulation), an die Grafikbibliothek **gekoppelt**. **Geringe Kopplung** macht Module unabhängig baubar, testbar und austauschbar (siehe E12).

### 7.7 Kamerasteuerung

`UpdateCamera` bewegt die Kamera passend zu einem Modus. Im Projekt verglichen:

| Modus | Verhalten | Einsatz |
|---|---|---|
| `CAMERA_ORBITAL` | kreist automatisch um das Ziel, ohne Eingabe | gleichmäßige Aufnahme, z. B. Backup-Video |
| `CAMERA_FREE` | frei steuerbar mit Maus und W/A/S/D | Live-Vorführung, eigene Blickwinkel |

Die Drehung wird aus der **Mausbewegung** zwischen zwei Frames berechnet. Stößt der Mauszeiger an den Fensterrand, kommt keine Bewegung mehr an. `DisableCursor()` versteckt den Zeiger und hält ihn im Fenster fest. Der Aufruf erfolgt **einmal** vor der Game Loop. Beendet wird das Programm dann mit Esc (`WindowShouldClose()`).
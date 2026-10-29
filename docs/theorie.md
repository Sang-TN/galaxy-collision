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

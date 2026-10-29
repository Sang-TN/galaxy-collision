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

Eine normale Zahl ohne Richtung heißt **Skalar**. Beispiele in der Simulation: Zeit, Masse, die Gravitationskonstante G.

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


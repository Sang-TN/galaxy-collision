# UML-Klassendiagramme

Die Diagramme sind in **Mermaid** geschrieben. GitHub stellt sie direkt als Grafik dar. Für die schriftliche Dokumentation können sie z. B. mit dem Mermaid Live Editor (mermaid.live) als Bild exportiert werden.

**Legende:** `+` = public, `-` = private, `$` = static, `*` = Methode ist `const`

---

## Übersicht

```mermaid
classDiagram
    direction LR
    class Vec3
    class Teilchenspeicher
    Teilchenspeicher "1" *-- "0..*" Vec3 : besteht aus
```

Der Teilchenspeicher **besteht aus** vielen `Vec3` (Komposition): Die Vektoren gehören zum Speicher und existieren nicht ohne ihn.

---

## Vec3 (`src/core/vec3.hpp`) – umgesetzt

```mermaid
classDiagram
    class Vec3 {
        +float x
        +float y
        +float z
        +Vec3()
        +Vec3(float x_, float y_, float z_)
        +operator+(const Vec3& other) Vec3*
        +operator-(const Vec3& other) Vec3*
        +operator*(float skalar) Vec3*
        +operator/(float skalar) Vec3*
        +length() float*
    }
```

---

## Teilchenspeicher (`src/core/teilchenspeicher.hpp`) – teilweise umgesetzt

```mermaid
classDiagram
    class Teilchenspeicher {
        -std::vector~Vec3~ positionen_
        -std::vector~Vec3~ geschwindigkeiten_
        -std::vector~Vec3~ beschleunigungen_
        +hinzufuegen(const Vec3& position, const Vec3& geschwindigkeit) void
        +anzahl() std::size_t*
        +positionen() std::span~Vec3~
        +positionen() std::span~const Vec3~*
        +geschwindigkeiten() std::span~Vec3~
        +beschleunigungen() std::span~Vec3~
    }
```

*Umgesetzt:* Attribute, `hinzufuegen`, `anzahl`. *Noch offen:* die `span`-Getter.

*Festgelegt:* deutsche Bezeichner; Vektoren `private`, damit die Invariante „alle drei gleich lang“ geschützt ist (siehe E9).

*Zugriff:* über `std::span` – Werte ändern ja, Größe ändern nein (siehe E10). Private Attribute enden auf `_` (z. B. `positionen_`), weil Attribut und Methode in C++ nicht denselben Namen haben dürfen. Die Getter heißen ohne Unterstrich (`positionen()`); ob es pro Vektor eine lesende `const`-Variante und eine ändernde Variante gibt, wird bei der Umsetzung festgelegt.
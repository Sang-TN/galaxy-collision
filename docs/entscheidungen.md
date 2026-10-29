# Entscheidungen

**cmake:**
- Reproduzierbarkeit und keine manuelle Vorarbeit benötigt.

## Folgerung für die Klasse Vec3

Ohne eigene Klasse müsste jede Rechnung dreimal geschrieben werden, einmal für x, y und z. Das ist unübersichtlich und fehleranfällig. Eine Klasse `Vec3` bündelt die drei Komponenten und stellt die Operationen bereit. Dadurch sieht der Code fast so aus wie die Formel auf dem Papier, z. B. `position + geschwindigkeit * dt`.

Bisher benötigte Operationen:

| Operation | Art | Abschnitt |
|---|---|---|
| Addition | Vektor + Vektor | 3.1 |
| Skalarmultiplikation | Vektor · Skalar | 3.2 |
| Subtraktion | Vektor − Vektor | 3.4 |
| Betrag | Länge eines Vektors | 3.5 |

raylib bringt einen eigenen Typ `Vector3` mit. Trotzdem wird eine eigene Klasse verwendet, weil die Physik nach der Projektarchitektur unabhängig von der Grafikbibliothek sein soll. Diese Entscheidung wird in `docs/entscheidungen.md` begründet.
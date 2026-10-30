# Tests und Messwerte

Jeder Test folgt dem Schema **Was → Wie → Erwartet → Ergebnis**.

| Nr. | Datum | Was wird getestet | Wie | Erwartet | Ergebnis |
|---|---|---|---|---|---|
| T1 | 30.10.2026 | `Vec3::length()` (Betrag) | Manueller Test in `viewer.cpp`: `Vec3 v(3, 4, 12)`, Ausgabe von `v.length()` mit `std::cout` | 13 (√(9 + 16 + 144) = √169, siehe `theorie.md` 3.5) | 13 ✔ |
| T2 | 30.10.2026 | `Teilchenspeicher::hinzufuegen` und `anzahl()` | Manueller Test in `viewer.cpp`: benannter Speicher, ein Stern hinzugefügt, Ausgabe von `anzahl()` | 1 | 1 ✔ |

**Hinweis:** T1 und T2 sind provisorische Tests. Automatisierte Tests mit doctest in `tests/` folgen. Die Testausgabe wird danach aus `viewer.cpp` entfernt.

**Noch nicht getestet:** `operator+`, `operator-`, `operator*`, `operator/`
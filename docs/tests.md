# Tests und Messwerte

Jeder Test folgt dem Schema **Was → Wie → Erwartet → Ergebnis**.

| Nr. | Datum | Was wird getestet | Wie | Erwartet | Ergebnis |
|---|---|---|---|---|---|
| T1 | 30.10.2026 | `Vec3::length()` (Betrag) | Manueller Test in `viewer.cpp`: `Vec3 v(3, 4, 12)`, Ausgabe von `v.length()` mit `std::cout` | 13 (√(9 + 16 + 144) = √169, siehe `theorie.md` 3.5) | 13 ✔ |
| T2 | 30.10.2026 | `Teilchenspeicher::hinzufuegen` und `anzahl()` | Manueller Test in `viewer.cpp`: benannter Speicher, ein Stern hinzugefügt, Ausgabe von `anzahl()` | 1 | 1 ✔ |
| T3 | 30.10.2026 | `zufaelligePunkte` und `positionen()`-Getter | Manueller Test in `viewer.cpp`: 500 Punkte, Radius 1, Seed 42; Ausgabe von `anzahl()` und der ersten Position; Programm zweimal gestartet | 500; x, y, z zwischen −1 und +1; beide Läufe identisch | 500; (−0.25092, 0.593086, 0.901429) in beiden Läufen ✔ |

**Hinweis:** T1 bis T3 sind provisorische Tests. Automatisierte Tests mit doctest in `tests/` folgen. Die Testausgabe wird danach aus `viewer.cpp` entfernt.

**Noch nicht getestet:** `operator+`, `operator-`, `operator*`, `operator/`
# KI-Protokoll

## 12.10.2026 – Projektplan und Git-Grundlagen

- **KI-System:** Claude Code, Anthropic, Modell Claude Opus 5.5
- **Datum:** 12.10.2026
- **Prompts:**
  - „okay lies bitte die md datei, wie werden nämlich was angehen und kannst auch ruhig sagen du davon hälst“
  - „ja am besten mit setup anfangen und dem repo, zur frage ich weiß nicht, was ist build/ überhaupt gemeint?“
  - weitere Rückfragen zu `git status`, `git add` und `git commit`
- **KI-Ausgabe (zusammengefasst):** Rückmeldung zum Projektplan mit vier Kritikpunkten (Abgabetermin, KI-Kennzeichnung, Halo in Stufe 2, Projekttitel). Erklärung von `build/`, `.gitignore`, Staging-Area und Commit. Hinweise zur Fehlersuche bei der `.gitignore`.
- **Zweck:** Plan prüfen lassen und Git-Grundlagen verstehen.
- **Eigene Bearbeitung und Überprüfung:** Repository, `.gitignore` und Commits selbst angelegt. Zwei eigene Fehler nach Hinweisen selbst gefunden und behoben. Ergebnis mit `git status` und `git log` geprüft. Die Kritikpunkte am Plan sind noch offen.

## 12.10.2026 – README

- **KI-System:** Claude Code, Anthropic, Modell Claude Opus 5.5
- **Datum:** 12.10.2026
- **Prompt:** „kannst du nicht einfach das README schreiben damit es auch gut aussieht? außerdem was für ein protokoll?“
- **KI-Ausgabe (zusammengefasst):** Vollständige `README.md` mit Kurzbeschreibung, Umfang, Meilensteinen, Technik und Dokumentationsübersicht.
- **Zweck:** Ansprechende Projektübersicht für das Repository.
- **Eigene Bearbeitung und Überprüfung:** Durchgelesen und inhaltlich mit `CLAUDE.md` abgeglichen.

## 17.10.2026 - CMake

- **KI-System:** Claude Code, Anthropic, Modell Claude Opus 5.5
- **Datum:** 17.10.2026
- **Prompt:** „okay will am projekt weiter arbeiten, … was wäre der nächste schritt“ und die Folge-Prompts zur Durchsicht der `CMakeLists.txt`
- **Ausgabe:** Erklärung von CMake, FetchContent, Target und Out-of-Source-Build; Hinweise auf Syntaxfehler in der eigenen `CMakeLists.txt` (fehlendes VERSION, Komma als Trennzeichen, fehlender Target-Name, absoluter Pfad)
- **Zweck:** Verständnis des Build-Systems, Code-Review
- **Eigene Bearbeitung:** `CMakeLists.txt` und `viewer.cpp` selbst geschrieben und nach den Hinweisen selbst korrigiert, Build selbst getestet

## 17.10.2026 - raylib

- **KI-System:** Claude Code, Anthropic, Claude Opus 5.5
- **Datum:** 17.10.2026
- **Prompt:** Fragen zur Versionierung von raylib und Bitte um Durchsicht von `CMakeLists.txt` und `viewer.cpp` („schau mal drüber“, „jetzt?“)
- **Ausgabe:** Erklärung von Git-Tag, Commit-Hash und FetchContent; Konzept der Game Loop als Pseudocode; Hinweise auf Fehler (Deklaration statt Aufruf, Code außerhalb von main, Python-Syntax, Groß-/Kleinschreibung)
- **Zweck:** Einbinden einer Bibliothek verstehen, Code-Review
- **Eigene Bearbeitung:** Code selbst geschrieben, raylib-Funktionen selbst im Cheatsheet gesucht, Fehler nach Hinweisen selbst korrigiert, Build und Fenster selbst getestet

## 29.10.2026 - Codespaces-Setup und Vektoren für Vec3

- **KI-System:** Claude (claude.ai), Anthropic, Claude Opus 5.5
- **Datum:** 29.10.2026
- **Prompt:** Fragen zum Arbeiten mit CMake und raylib in GitHub Codespaces („kann ich auf codespace überhaupt damit arbeiten“), Bitte um Erklärung des Vorgehens in M1 („ich muss erstmal selber verstehen, was ich genau jetzt machen muss“), Bitte um Strukturierung der eigenen Notizen in `theorie.md`
- **Ausgabe:** Hinweise zu fehlenden Linux-Paketen (RandR/X11-Header) und zur fehlenden Grafikausgabe in Codespaces; Kolloquiumsfragen zu M0 mit Bewertung; schrittweise Erklärung von Vektoren, Skalaren und Vektoroperationen (Addition, Subtraktion, Skalarmultiplikation, Division, Betrag über den Satz des Pythagoras) mit Übungsfragen; Zuordnung der Operationen zur Gravitationsformel; gegliederte Fassung von `theorie.md`
- **Zweck:** Entwicklungsumgebung einrichten, mathematische Grundlagen für die Klasse `Vec3` verstehen, Theoriekapitel vorbereiten
- **Eigene Bearbeitung:** Build-Fehler selbst im Terminal behoben; Kolloquiumsfragen 1–3 selbst beantwortet; Rechenaufgaben (Abstandsvektor, Betrag in 2D und 3D) selbst gelöst, nach Hinweisen Fehler selbst korrigiert; Notizen selbst erstellt, Gliederung von der KI übernommen, Text wird für die Dokumentation in eigenen Worten umgeschrieben

## 30.10.2026 - Klasse Vec3: Operatorüberladung und Code-Review
 
- **KI-System:** Claude (claude.ai), Anthropic, Claude Opus 5.5
- **Datum:** 30.10.2026
- **Prompt:** Fragen zu Startwerten, `public`/`private`, Referenzen und `const` („wahrscheinlich eine Referenz zum anderen Vec3?“, „final? static?“), Bitte um Hilfe beim Rumpf von `operator+` („beim Rumpf musst du mir bisschen helfen“), Bitte um Review des eigenen Codes von `vec3.hpp`, Bitte um Festhalten von Theorie und Entscheidungen
- **Ausgabe:** Erklärung von Nullvektor und uninitialisierten Variablen, Kapselung und Invarianten, Operatorüberladung, Wert- und Referenzübergabe, `const`-Parametern und konstanten Methoden, Inlining, IEEE 754 (inf/NaN), `std::sqrt`; schrittweise Hinweise statt fertiger Lösung; Hinweise auf Fehler (Initialisierung, endlose Rekursion, Komponenten beim Skalar, fehlendes `#include`, fehlendes `return`/`const`); Fassung der Abschnitte 4.7–4.11 in `theorie.md` und der Entscheidungen E4–E6
- **Zweck:** C++-Konzepte für die Klasse `Vec3` verstehen, Code-Review, Dokumentation vorbereiten
- **Eigene Bearbeitung:** `vec3.hpp` vollständig selbst geschrieben; Entscheidungen (`float`, `class` mit `public`) selbst getroffen; Fehler nach Hinweisen selbst gefunden und korrigiert; Texte von der KI übernommen, werden für die Dokumentation in eigenen Worten umgeschrieben

## 30.10.2026 (2) - Include-Verzeichnis, AoS/SoA und Teilchenspeicher

- **KI-System:** Claude (claude.ai), Anthropic, Claude Opus 5.5
- **Datum:** 30.10.2026
- **Prompt:** Fragen zum Einbinden von `vec3.hpp` über CMake, zu AoS und SoA („bei AoS weil die daten ja in einer reihe sind“), zu `std::vector`, `private` und Zugriff von außen („mit getter aber keiner setter“), Bitte um Hilfe beim Teilchenspeicher („ab hier weiß ich nicht weiter“), Bitte um UML-Diagramme und Dokumentation
- **Ausgabe:** Erklärung von `target_include_directories`, Cache und Cache-Lokalität, AoS/SoA, `std::vector`, Invarianten, Kopie/Referenz/`std::span`, `push_back`, `size()`, `std::size_t`, temporären Objekten und Most Vexing Parse; Pseudocode für `hinzufuegen`; Hinweise auf Fehler statt fertiger Lösung; Texte für `theorie.md` (5.1–5.5), `entscheidungen.md` (E7–E10), `tests.md` (T1, T2), `uml.md` und README
- **Zweck:** Datenstruktur für viele Sterne entwerfen und begründen, Code-Review, Dokumentation vorbereiten
- **Eigene Bearbeitung:** CMake-Zeile, Tests in `viewer.cpp` und `teilchenspeicher.hpp` selbst geschrieben; Entscheidung für SoA, `private` und deutsche Bezeichner selbst getroffen; Fehler nach Hinweisen selbst korrigiert; Texte von der KI übernommen, werden in eigenen Worten umgeschrieben

## 30.10.2026 (3) - span-Getter und zufällige Punktwolke

- **KI-System:** Claude (claude.ai), Anthropic, Claude Opus 5.5
- **Datum:** 30.10.2026
- **Prompt:** Fragen zur roten Markierung von `std::span` im Editor („qualified name is not allowed“), zum Seed („dann kann man zurücktracen?“), zur `for`-Schleife und zu `verteilung(generator)` („was muss statt zufall rein?“), Bitte um Review von `teilchenspeicher.hpp`, `zufall.hpp` und `viewer.cpp`
- **Ausgabe:** Erklärung von Überladung mit `const`, IntelliSense-Einstellung, Pseudozufall und Seed, `<random>` (Generator, Verteilung), `inline` bei freien Funktionen, unbestimmter Auswertungsreihenfolge von Argumenten, Groß-/Kleinschreibung unter Linux; Rezept und Pseudocode für `zufaelligePunkte`; Hinweise auf Fehler; Texte für `theorie.md` (5.6, 6.1–6.5), E11, T3, `uml.md`
- **Zweck:** Zugriff auf den Teilchenspeicher und Startpositionen umsetzen, Code-Review, Dokumentation
- **Eigene Bearbeitung:** Getter, `zufall.hpp` und Test selbst geschrieben; Fehler nach Hinweisen selbst korrigiert; Test zweimal ausgeführt und Ergebnis selbst geprüft; Texte von der KI übernommen, werden in eigenen Worten umgeschrieben

## 31.10.2026 - Kamera und 3D-Modus in raylib

- **KI-System:** Claude Code, Anthropic, Claude Opus 5.5
- **Datum:** 31.10.2026
- **Prompt:** „okay claude wir sind mit M1 fast durch es fehlen denke ich noch die punkte im raum oder? schau mal“, Fragen zu den Kamera-Feldern („position wo die kamere halt sich gerade befindet mit target vielleicht was der fokus gerade ist und up soviel wie die höhe?“), zu `BeginMode3D`, `EndMode3D` und `DrawGrid` („was machen die drei“), Bitte um einfachere Erklärung („das ist ein bereich wovon ich wirklich null ahnung bisher habe“), Frage nach Startwerten („was für werte sollte ich nehmen?“)
- **Ausgabe:** Plan für den Rest von M1 in drei Teilschritten; Erklärung von Kamera, Projektion, Sichtfeld und Up-Vektor; Vergleich der Zeichenschleife mit einem Daumenkino und des 3D-Modus mit einem Fotografen; Startwerte für `Camera3D` mit Begründung; Hinweise auf Fehler (Signatur statt Aufruf, Zeichnen außerhalb der Schleife, falscher Variablenname, Initialisierung mit runden Klammern) statt fertiger Lösung
- **Zweck:** Grundlagen der 3D-Darstellung in raylib verstehen, Code-Review
- **Eigene Bearbeitung:** Kamera und Zeichenschleife in `viewer.cpp` selbst geschrieben; Feldreihenfolge von `Camera3D` selbst in `raylib.h` nachgeschlagen; Fehler nach Hinweisen selbst korrigiert; Ergebnis durch Bauen und Starten selbst geprüft (Gitter sichtbar)

## 31.10.2026 (2) - Umwandlung Vec3 → Vector3 und Punktwolke zeichnen

- **KI-System:** Claude Code, Anthropic, Claude Opus 5.5
- **Datum:** 31.10.2026
- **Prompt:** Antwort auf die Frage nach der Abhängigkeit („vielleicht wegen performance gründen bei mehreren sternen?“, „auch die raylib.h“), Fragen zu PowerShell („warum geht touch umwandlung.hpp nicht“), zum Pseudocode und zu Headern („was meinst du mit den pfeil zu vector3 genau? … was ist an den headern falsch?“), zur Schleife („also eine for each schleife oder wie genau?“, „mit const und refernz oder nicht?“), Bitte um Formulierung der Doku-Einträge
- **Ausgabe:** Erklärung von Kopplung und Abhängigkeitsrichtung (`render/` → `core/`), Headless-Betrieb; PowerShell-Befehl `New-Item`; Erklärung von Rückgabetyp, Include-Pfaden und Aggregat-Initialisierung von `Vector3`; Pseudocode für Umwandlung und Zeichenschleife; Erklärung der bereichsbasierten for-Schleife im Vergleich zu Python und von Kopie vs. `const`-Referenz; Hinweise auf Fehler statt fertiger Lösung; Texte für E12, Projekttagebuch und dieses Protokoll
- **Zweck:** Punktwolke darstellen, Trennung von Physik und Darstellung verstehen und begründen, Code-Review, Dokumentation
- **Eigene Bearbeitung:** `umwandlung.hpp` und Zeichenschleife in `viewer.cpp` selbst geschrieben; Fehler nach Hinweisen selbst korrigiert; Ergebnis durch Bauen und Starten selbst geprüft und per Screenshot festgehalten; Texte von der KI übernommen, werden in eigenen Worten umgeschrieben

## 31.10.2026 (3) - Kamerasteuerung, Bildrate und Doku zu M1

- **KI-System:** Claude Code, Anthropic, Claude Opus 5.5
- **Datum:** 31.10.2026
- **Prompt:** Antwort auf die Frage nach der Form der Punktwolke („sieht eher aus wie ein würfel“), zu Zeiger und Kopie („weil beginmode3d ja nur eine sache wissen muss … und updatecamera ja jedesmal wissen muss wo die kamera sich befindet“), Vergleich der Kameramodi („orbital dreht sich einfach ohne mein input aber free ist gerade scuffed“), Bitte um Review („so?“, „jetzt?“), Bitte um Ergänzung der Doku mit Screenshots („kannst du das ergänzen in die docs wie theorie, uml, tests mit den screenshots hier, und den restlichen?“)
- **Ausgabe:** Erklärung der Würfelform und der Verwerfungsmethode; Erklärung von Zeiger, Adressoperator und warum raylib (C) Zeiger statt Referenzen verwendet; EVA-Prinzip in der Game Loop; Ursache des Ruckelns bei `CAMERA_FREE`; Hinweise auf Fehler (Aufruf in jedem Frame, überflüssiges `HideCursor`) statt fertiger Lösung; Kolloquiumsfragen zu M1; Texte für `theorie.md` (6.6, 7.1–7.7), `tests.md` (T4–T6, Abbildungen), `uml.md` (Umwandlung, Modulabhängigkeiten), E11 (Einschränkung), E13, Projekttagebuch und dieses Protokoll
- **Zweck:** Kamerasteuerung umsetzen, Game Loop verstehen, M1 dokumentieren
- **Eigene Bearbeitung:** `UpdateCamera`, `SetTargetFPS` und `DisableCursor` selbst eingebaut; Cursor-Funktion selbst im Cheatsheet gefunden; beide Kameramodi selbst ausprobiert und Entscheidung selbst getroffen; Fehler nach Hinweisen selbst korrigiert; Screenshots selbst erstellt; Texte von der KI übernommen, werden in eigenen Worten umgeschrieben
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
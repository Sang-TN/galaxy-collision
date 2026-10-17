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
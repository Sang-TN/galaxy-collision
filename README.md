# Galaxienkollision – Milchstraße × Andromeda

Eine 3D-N-Körper-Simulation in C++ mit raylib: Zwei Scheibengalaxien kollidieren und bilden dabei Gezeitenarme.

Abschlussprojekt zum staatlich geprüften IT-Assistenten an der Höheren Berufsfachschule Informationstechnik, BBS 1 Mainz.

> **Stand:** M0 (Setup) ist abgeschlossen. M1 (Punkte im Raum) ist bis auf die Darstellung fertig: Vektorklasse `Vec3`, Teilchenspeicher und zufällige Punktwolke sind umgesetzt und getestet. Eine Simulation gibt es noch nicht.

## Worum es geht

Wenn zwei Galaxien aneinander vorbeiziehen, reißt die Schwerkraft lange Sternströme aus den Scheiben, die sogenannten Gezeitenarme. Dieses Projekt simuliert einen solchen Vorbeiflug und zeigt ihn in Echtzeit in 3D.

Vorbild ist das Modell von Toomre und Toomre (1972), das dieses Verhalten schon mit sehr einfachen Annahmen nachbilden konnte.

Der Schwerpunkt liegt auf der Informatik: Algorithmen, Datenstrukturen, Laufzeitmessung und eine saubere objektorientierte Architektur.

## Geplanter Umfang

| Stufe | Inhalt | Rechenaufwand |
|---|---|---|
| 1 (Pflicht) | Zwei schwere Galaxienzentren und zehntausende masselose Teststerne in rotierenden Scheiben | O(N) |
| 2 (Kür) | Alle Sterne ziehen sich gegenseitig an: erst Brute Force, dann Barnes-Hut mit Octree | O(N²), dann O(N log N) |

## Meilensteine

- [ ] **M0 – Setup:** Git, CMake, raylib, ein leeres Fenster
- [ ] **M1 – Punkte im Raum:** eigene `Vec3`-Klasse, Teilchenspeicher, drehbare Kamera
- [ ] **M2 – Eine stabile Galaxie:** Teststerne auf Kreisbahnen um ein Zentrum
- [ ] **M3 – Toomre-Kollision:** zwei Galaxien, prograde und retrograde Szenarien
- [ ] **M4 – Brute-Force-Eigengravitation:** mit Energieüberwachung
- [ ] **M5 – Barnes-Hut:** Octree, Kraftfehler und Laufzeitvergleich
- [ ] **M6 – Snapshots:** Simulation speichern und abspielen
- [ ] **M7 – Kür:** Halo, Parallelisierung, Video

## Technik

- C++20
- CMake ab Version 3.20
- raylib für Fenster und 3D-Darstellung
- doctest für Tests
- clang-format für einheitliche Formatierung

## Projektstruktur

```
galaxy-collision/
├── CMakeLists.txt            # Build-Konfiguration, bindet raylib per FetchContent ein
├── apps/
│   └── viewer.cpp            # Programm mit Fenster (Live-Ansicht)
├── src/
│   ├── core/
│   │   ├── vec3.hpp          # Vektorklasse für Positionen, Geschwindigkeiten, Beschleunigungen
│   │   └── teilchenspeicher.hpp  # Speicher aller Sterne (Struct of Arrays)
│   └── setup/
│       └── zufall.hpp        # Zufällige Startpositionen mit festem Seed
└── docs/                     # Dokumentation (siehe unten)
```

Geplant sind weitere Module unter `src/`: `physics/` (Kraftberechnung), `integrator/` (Zeitschritte), `io/` (Snapshots) und `render/` (Darstellung), außerdem `tests/` und `bench/`.

## Bauen und Starten

Voraussetzungen: C++20-Compiler, CMake ab Version 3.20, Git. raylib wird beim ersten Konfigurieren automatisch heruntergeladen.

Unter Linux werden zusätzlich die X11-/OpenGL-Entwicklungspakete benötigt:

```
sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev
```

Konfigurieren, bauen und starten:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/viewer
```

Hinweis: In Umgebungen ohne Bildschirm (z. B. GitHub Codespaces) lässt sich das Programm bauen, das Fenster öffnet sich aber nicht.

### Windows

Voraussetzungen einmalig installieren (Visual Studio Build Tools mit MSVC-Compiler und CMake):

```
winget install --id Microsoft.VisualStudio.2022.BuildTools --override "--passive --wait --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
winget install --id Kitware.CMake
```

Konfigurieren, bauen und starten (im Ordner `galaxy-collision`):

```
cmake -S . -B build
cmake --build build --config Release
.\build\Release\viewer.exe
```

Unter Windows wird Debug oder Release erst beim Bauen mit `--config` gewählt. Ohne `--config` wird Debug gebaut, das Programm liegt dann in `build\Debug\`.

## Dokumentation

| Datei | Inhalt |
|---|---|
| [docs/theorie.md](docs/theorie.md) | Physikalische und informatische Grundlagen, Herleitungen |
| [docs/entscheidungen.md](docs/entscheidungen.md) | Entscheidungen mit Alternativen und Begründung |
| [docs/tests.md](docs/tests.md) | Tests und Messwerte |
| [docs/uml.md](docs/uml.md) | UML-Klassendiagramme |
| [docs/projekttagebuch.md](docs/projekttagebuch.md) | Arbeitsprotokoll pro Sitzung |
| [docs/ki-protokoll.md](docs/ki-protokoll.md) | Kennzeichnung der KI-Nutzung |
| [docs/quellen.md](docs/quellen.md) | Quellenverzeichnis |

## KI-Nutzung

In diesem Projekt wird ein KI-Assistent als Lernhilfe eingesetzt, für Erklärungen, Herleitungen und Code-Review. Der Programmcode wird selbst geschrieben. Jede relevante Nutzung ist in [docs/ki-protokoll.md](docs/ki-protokoll.md) festgehalten.

## Quelle

Toomre, Alar; Toomre, Juri (1972), „Galactic Bridges and Tails“, The Astrophysical Journal, Jahrgang 178, Seiten 623–666.
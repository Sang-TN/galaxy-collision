# Projekt: Galaxienkollision – Milchstraße × Andromeda

Eine 3D-N-Körper-Simulation in C++ mit raylib, in der zwei Scheibengalaxien kollidieren und dabei Gezeitenarme bilden. Das Projekt ist das **Abschlussprojekt zum staatlich geprüften IT-Assistenten** (Höhere Berufsfachschule Informationstechnik, BBS 1 Mainz).

**Zeitrahmen:** ca. 2–3 Monate. **Abgabetermin:** noch offen.

---

## 1. Wer ich bin und was ich schon kann

- Ich heiße Tien und bin Schüler an der HBFIT (IT-Assistent + Fachhochschulreife).
- **C++:** Am vertrautesten bin ich mit Objektorientierung (Klassen, Objekte).
- **Physik und Numerik:** Hier bin ich noch nicht sicher. Bitte nichts voraussetzen und von Grund auf erklären.
- Außerdem: Python, SQL.
- **Setup:** macOS, VS Code, Homebrew.

---

## 2. Deine Rolle (wichtigste Regeln)

1. **Du bist Professor und Architekt, nicht mein Programmierer.** Du gibst mir Herleitungen, Konzepte und Pseudocode. **Den Code schreibe ich selbst.** Ich muss am Ende jede Zeile in der Prüfung erklären können.
2. **Code nur auf ausdrückliche Nachfrage.** Das gilt für alles, auch für CMake, `.gitignore` oder Build-Skripte. Wenn ich ausdrücklich nach Code frage, erklärst du kurz, was er tut.
3. **Kleinste mögliche Schritte.** Immer nur ein Teilschritt. Vor jedem Schritt: kurz das Ziel nennen und mir eine Verständnisfrage stellen.
4. **Code-Review statt Fehler fixen.** Wenn mein Code einen Fehler hat, gib mir einen Hinweis, wo ich suchen soll. Erst wenn ich nach zwei Hinweisen nicht weiterkomme, wirst du konkreter.
5. **Keine Überarbeitungen im großen Stil.** Lieber kleine, integrierte Verbesserungen. Wenn etwas wie Overkill wirkt, lass es weg oder frag nach.
6. **Kurze, direkte Antworten auf Deutsch.** Wenn ich nach einfacher Sprache frage, erkläre es einfacher.
7. **Herleitungen mathematisch sauber**, aber Schritt für Schritt, damit ich sie selbst nachvollziehen und in `docs/theorie.md` in eigenen Worten festhalten kann.
8. **Korrekte Fachsprache.** Nenne Fachbegriffe beim richtigen Namen und erkläre sie beim ersten Auftreten. In der Prüfung wird darauf geachtet.
9. **Nach jedem abgeschlossenen Teilschritt:**
   - einen Commit vorschlagen (mit Commit-Message),
   - mich an den Eintrag im Projekttagebuch erinnern (`docs/projekttagebuch.md`),
   - einen Eintrag fürs KI-Protokoll vorschlagen (`docs/ki-protokoll.md`, Format siehe Abschnitt 10),
   - den Abschnitt „Aktueller Stand“ unten aktualisieren.
10. **Nach jedem abgeschlossenen Meilenstein:** Stell mir 3–5 Fragen, wie sie im Kolloquium kommen könnten (fachliche Grundlagen, begründete Entscheidungen, Code erklären, Verbesserungen, Verknüpfung mit anderen Themen). Bewerte meine Antworten ehrlich.

---

## 3. Projektziel und Umfang

**Ziel:** Eine realitätsnahe, visuell anschauliche Simulation einer Galaxienkollision. Die IT-Tiefe liegt in Algorithmen (Barnes-Hut), Datenstrukturen (Octree), Performance und sauberer objektorientierter Architektur, nicht in komplizierter Physik.

**Stufe 1 – Toomre-Ansatz (Pflicht):**
Zwei schwere Galaxienzentren, die sich gegenseitig anziehen, plus zehntausende **masselose Teststerne** in rotierenden Scheiben. Komplexität O(N). Schon das erzeugt realistische Gezeitenarme (vgl. Toomre & Toomre 1972, Antennen-Galaxien).

**Stufe 2 – Volle Eigengravitation (Kür):**
Alle Sterne ziehen sich gegenseitig an. Brute Force O(N²) als Referenz, dann **Barnes-Hut mit Octree** (O(N log N)). Dazu Snapshots speichern und abspielen.

**Optional:** Dunkle-Materie-Halo verfeinern, Parallelisierung (OpenMP), Video-Export.

**Sicherheitsnetz:** Ist Stufe 1 zur Halbzeit nicht fertig, entfällt Barnes-Hut. Die restliche Zeit geht dann in Feinschliff, Dokumentation und Präsentation.

**Erfolgskriterien (Grundlage für den Soll-Ist-Vergleich):**
- Eine einzelne Galaxie bleibt über viele Umläufe stabil.
- Die Kollision erzeugt sichtbar Gezeitenarme. Ein prograder gegenüber einem retrograden Vorbeiflug zeigt den erwarteten Unterschied.
- Barnes-Hut-Kräfte stimmen innerhalb einer gemessenen Toleranz mit Brute Force überein.
- Ein gemessener Laufzeitvergleich zeigt O(N²) gegen O(N log N).

---

## 4. Physikalisches Modell (Referenz, Details erarbeiten wir gemeinsam)

- **Einheiten:** Eigene Simulationseinheiten mit G = 1. Vorschlag: Länge 1 ≈ 10 kpc, Masse 1 ≈ 10¹¹ Sonnenmassen, daraus ergibt sich eine Zeiteinheit von ca. 47 Mio. Jahren. Endgültig festlegen wir das in M2.
- **Gravitation mit Plummer-Softening:** a = G·M·r / (|r|² + ε²)^(3/2)
- **Integrator:** Velocity-Verlet (Kick–Drift–Kick). Zentren und Sterne werden im selben Zeitschritt integriert.
- **Startbedingungen Galaxie:** Sterne auf einer Scheibe, Kreisbahngeschwindigkeit aus dem Gleichgewicht von Zentripetal- und Gravitationskraft (mit Softening). Die Herleitung machen wir in M2.
- **Startbedingungen Kollision:** Zwei Galaxien auf einer (annähernd) parabolischen Bahn mit festgelegtem Perizentrumsabstand. Die Scheiben lassen sich neigen und prograd oder retrograd ausrichten.
- **Kontrolle:** Gesamtenergie (in Stufe 2) bzw. Bahnstabilität (in Stufe 1) überwachen.

---

## 5. Architektur

Physik, Darstellung und Datenhaltung sind strikt getrennt.

```
galaxy-collision/
├── CMakeLists.txt
├── README.md
├── CLAUDE.md
├── .gitignore
├── src/
│   ├── core/        # Vec3, Speicherung der Teilchen
│   ├── physics/     # Kraftberechnung: toomre, bruteforce, barneshut
│   ├── integrator/  # Velocity-Verlet
│   ├── setup/       # Startbedingungen: Galaxie, Kollisionsszenarien
│   ├── io/          # Snapshots (binär) schreiben/lesen
│   └── render/      # raylib: Kamera, Punkte zeichnen, UI
├── apps/
│   ├── viewer.cpp   # Live-Ansicht (Stufe 1) bzw. Abspielen (Stufe 2)
│   └── sim.cpp      # Headless-Simulation, schreibt Snapshots (Stufe 2)
├── tests/           # Kraftvergleich, Energie, Stabilität
├── bench/           # Laufzeitmessungen → CSV
└── docs/            # siehe Abschnitt 9
```

**Lernthemen, die wir bewusst besprechen:**
- Array of Structs vs. Struct of Arrays (Cache-Effizienz)
- Octree-Aufbau, Rekursion, Speicher-Pool statt `new` pro Knoten
- Öffnungswinkel θ: Genauigkeit gegen Geschwindigkeit
- Effizientes Zeichnen vieler Punkte (ein Mesh / Batch statt einzelner Draw-Calls), additives Blending
- Binäres Snapshot-Format (Datenmenge: N × 6 Werte × 4 Byte pro Snapshot)

---

## 6. Technik

- **C++20**, **CMake ≥ 3.20**
- **raylib** über CMake `FetchContent` (reproduzierbar, funktioniert auch auf anderen Rechnern ohne Homebrew-Installation)
- **Tests:** doctest über `FetchContent` (leichtgewichtig)
- **Compiler-Flags:** Debug mit `-Wall -Wextra -g`, Release mit `-O2`/`-O3`
- **Formatierung:** clang-format
- **Später (optional):** OpenMP. Auf macOS braucht Apple Clang dafür `libomp` (Homebrew).

Jede Wahl einer Bibliothek oder eines Werkzeugs braucht eine **fachliche Begründung** in `docs/entscheidungen.md`. Im Kolloquium wird danach gefragt.

---

## 7. Meilensteine (jeweils mit Definition of Done)

- **M0 – Setup:** Git-Repo, CMake-Projekt, raylib per FetchContent, ein leeres Fenster öffnet sich. README-Gerüst und `docs/`-Dateien anlegen. GitHub-Repo erstellt und erster Push.
  *Fertig, wenn:* `cmake --build` läuft und ein Fenster erscheint.
- **M1 – Punkte im Raum:** Eigene `Vec3`-Klasse, Teilchenspeicher, ein paar hundert zufällige Punkte in 3D mit drehbarer Kamera. Erstes UML-Klassendiagramm.
  *Fertig, wenn:* Ich SoA vs. AoS erklären kann und meine Wahl in `docs/entscheidungen.md` begründet ist.
- **M2 – Eine stabile Galaxie:** Ein schweres Zentrum mit Teststernen auf Kreisbahnen. Herleitung der Kreisbahngeschwindigkeit, Einheiten festlegen.
  *Fertig, wenn:* Die Galaxie über mehrere Umläufe stabil rotiert, mit einer messbaren Kontrolle (z. B. mittlerer Radius bleibt konstant).
- **M3 – Toomre-Kollision:** Zwei Galaxien, parabolische Bahn, Szenarien prograd/retrograd/geneigt, additives Blending, Farbe nach Herkunft.
  *Fertig, wenn:* Gezeitenarme entstehen und der prograd/retrograd-Unterschied sichtbar ist. **Stufe 1 abgeschlossen.**
- **M4 – Brute-Force-Eigengravitation:** Alle Sterne ziehen sich an (kleines N), Energieüberwachung.
  *Fertig, wenn:* Die Energiedrift gemessen und dokumentiert ist.
- **M5 – Barnes-Hut:** Octree-Aufbau, Schwerpunkte der Knoten, Kraftberechnung mit θ.
  *Fertig, wenn:* Der Kraftfehler gegenüber Brute Force gemessen ist und die Laufzeitkurve (N gegen Zeit) als CSV und Grafik vorliegt.
- **M6 – Snapshots und Abspielen:** `sim` schreibt binäre Snapshots, `viewer` spielt sie flüssig ab.
  *Fertig, wenn:* Eine volle Kollision mit vielen Sternen abspielbar ist.
- **M7 – Kür:** Halo, Parallelisierung, Video/GIF für README und Präsentation.

---

## 8. Git-Workflow

- Kleine Commits, ein Teilschritt = ein Commit.
- Ein Branch pro Meilenstein (`m2-stabile-galaxie`), Merge nach `main`, wenn die Definition of Done erfüllt ist.
- `build/`, `snapshots/` und große Dateien gehören nicht ins Repo.
- Das GitHub-Repo erstelle ich entweder selbst auf github.com oder per `gh repo create`. Die Anmeldung bei GitHub mache ich selbst.

---

## 9. Prüfungsvorgaben der Schule

Stand: Vorgaben aus dem Probedurchlauf. **Für die echte Prüfung noch einmal mit dem Betreuer abgleichen.**

### 9.1 Bewertung
- Prüfungsteil 1 (Arbeits- und Vorgehensweise, Arbeitsergebnis, Dokumentation) und Prüfungsteil 2 (Präsentation + Fachgespräch) zählen je zur Hälfte.
- Teil 1 schlechter als 4 → Prüfung nicht bestanden. Fachgespräch oder Teil 2 insgesamt schlechter als 4 → nicht bestanden.

### 9.2 Gliederung der schriftlichen Dokumentation

| Nr. | Kapitel | Umfang | Quelle im Repo |
|---|---|---|---|
| 1 | Deckblatt (Name, Schule, Bildungsgang, Klasse HBF IT 24 A, Schuljahr, Thema, Projektleiter/in, Zeitraum, Abgabetermin) | – | – |
| 2 | Inhaltsverzeichnis | – | – |
| 3 | **Theoretische Grundlagen** (Fließtext) | **min. 2 Seiten** | `docs/theorie.md` |
| 4 | **Zeitplanung** (Gantt oder Arbeitspakete + Milestones) | **max. 1 Seite** | Abschnitt 7 + `docs/projekttagebuch.md` |
| 5 | **Durchführung:** Planung (UML) und Umsetzung **inkl. fachlicher Begründung der Vorgehensweise** | **min. 6 Seiten ohne Code** | `docs/entscheidungen.md`, `docs/tests.md` |
| 6 | Projektablauf: **Wochenberichte in Tabellenform** | **max. 1 Seite** | `docs/projekttagebuch.md` |
| 7 | **Projektergebnis:** Soll-Ist-Vergleich Zeit, Soll-Ist-Vergleich Ergebnis, Verbesserungen/Erweiterungen, kritische Reflexion/Fazit | **min. 2 Seiten** | Abschnitt 3 + `docs/tests.md` |
| 8 | Quellenverzeichnis (ohne Kapitelnummer) | – | `docs/quellen.md` |
| 9 | Selbstständigkeitserklärung | – | – |
| 10 | Abkürzungsverzeichnis | – | – |
| 11 | ggf. Tabellenverzeichnis | – | – |
| 12 | Anhang (z. B. vollständiger Code, ohne Kapitelnummer) | – | Repo |

**Wichtig:** Im Probedurchlauf mussten **theoretische Grundlagen und Zeitplanung früh abgegeben** werden (Ende des 2. Projekttags), danach gab es ein **Zwischengespräch**. Diese beiden Kapitel haben deshalb Vorrang.

**Kandidaten für Kapitel 3 (Theorie):** Grundprinzipien der OOP und ihre Anwendung im Projekt, Bibliotheken (raylib), Newton'sche Gravitation und Kreisbewegung, numerische Integration (Velocity-Verlet), Komplexität und Barnes-Hut/Octree.

### 9.3 Formale Anforderungen (für das spätere Word/PDF-Dokument)
- Dateiname: `Vorname_Nachname_Klasse.pdf`, Abgabe im Sichthefter
- Umfang ca. 10–15 Seiten Text (ohne Deckblatt, Verzeichnisse, Abbildungen, Tabellen, Anhang)
- Arial 12 pt, Zeilenabstand 1,5, Fußnoten 10 pt, längere Zitate einzeilig 11 pt
- Ränder: links 3 cm, rechts 2 cm, oben/unten 2 cm
- Kopfzeile mit Name, Kurztitel und Seitenzahl (ab Seite 2)
- Blocksatz ohne Silbentrennung, Kapitelüberschriften fett, Dezimalgliederung
- Abbildungen/Tabellen fortlaufend nummeriert, Überschrift darüber, Quellenangabe darunter
- Abkürzungen beim ersten Auftreten ausschreiben
- Wissenschaftliche Sprache, korrekte Rechtschreibung

### 9.4 Präsentation (15 Min., PowerPoint)
- Gliederung: Themenstellung → Projektergebnis (Live-Vorführung) → **fachliche Begründung (Hauptaspekt)** → Fazit & Ausblick
- Korrekte Fachsprache
- **Eigenleistung hervorheben und klar von Quellen und KI abgrenzen**
- Wochenberichte gehören nicht in die Präsentation
- Ein Video der Simulation als Backup für die Live-Vorführung einplanen

### 9.5 Kolloquium (15 Min.)
Fragen zu: fachlichen Grundlagen, Vorgehen und Durchführung (begründete Auswahl von Bibliotheken, Programmierstil, Software), Projektergebnis (**Programmcode erklären**), Verbesserungen und Erweiterungen, Verknüpfungen mit anderen Themenbereichen.

---

## 10. Dokumentation im Repo

```
docs/
├── theorie.md          # Kapitel 3: Herleitungen und Grundlagen in meinen eigenen Worten
├── entscheidungen.md   # Kapitel 5: Jede Entscheidung mit Alternativen und fachlicher Begründung
├── tests.md            # Kapitel 5/7: Was getestet wurde, wie, Ergebnis, Messwerte
├── projekttagebuch.md  # Kapitel 4/6/7: Datum, Tätigkeit, Dauer, Probleme
├── ki-protokoll.md     # Kennzeichnung der KI-Nutzung (Pflicht)
└── quellen.md          # Kapitel 8: Quellen im Schulformat
```

**Projekttagebuch:** Pro Sitzung eine Zeile: Datum | Meilenstein | Tätigkeit | Dauer | Problem/Lösung. Daraus entstehen die Wochenberichte und der Soll-Ist-Vergleich.

**KI-Protokoll (Vorgabe der Schule):** Für jede relevante KI-Nutzung:
- Name des KI-Systems, Anbieter, verwendetes Modell
- Datum der Nutzung
- vollständiger Prompt
- relevante KI-Ausgabe (zusammengefasst)
- Zweck der Verwendung
- eigene Bearbeitung und Überprüfung

Quellenangabe im Literaturverzeichnis: *Anbieter (Jahr), Name des KI-Systems, Modell [Generative AI]. Beschreibung der Ausgabe. Datum. URL, Zweck, eigene Bearbeitung und Überprüfung.*

**Selbstständigkeitserklärung:** Die Schulvorlage spricht von „ohne fremde Hilfe“. Wie die KI-Nutzung damit vereinbart und gekennzeichnet wird, kläre ich früh mit meinem Betreuer und halte es schriftlich fest.

**Quellenformat (Schule):**
- Online: *Name/Website (Jahr), Titel, Erscheinungsdatum, URL, letzter Zugriff: Datum.*
- Buch: *Name, Vorname (Jahr), Titel, Auflage, Erscheinungsort.*
- Fachzeitschrift: *Name, Vorname (Jahr), „Titel“, Zeitschrift, Jahrgang, Ausgabe, Seiten.*

---

## 11. Aktueller Stand

- **M0 läuft.** Erledigt: lokales Git-Repo, `.gitignore`, `docs/`-Gerüst, README, erste Einträge in Projekttagebuch und KI-Protokoll. CMake installiert, minimales CMake-Projekt (C++20, Target `viewer` aus `apps/viewer.cpp`, gibt „Hallo Galaxie“ aus), Out-of-Source-Build in `build/`. raylib 5.5 per FetchContent (Git-Tag) eingebunden, `viewer` öffnet ein schwarzes 1280×720-Fenster (Game Loop).
- **Nächster Schritt:** GitHub-Repo erstellen und erster Push → damit ist M0 abgeschlossen (danach Kolloquiumsfragen zu M0).
- **Offen mit dem Betreuer:** Abgabetermin, Umgang mit KI-Nutzung und Selbstständigkeitserklärung.
- Noch keine Simulationslogik implementiert.
- Parallel früh beginnen: `docs/theorie.md` und Zeitplanung (siehe 9.2).

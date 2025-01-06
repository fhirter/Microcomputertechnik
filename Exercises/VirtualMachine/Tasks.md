# Gruppenarbeit virtuelle Maschine

## Lernziele und Kompetenzen

Die Studierenden

- kennen die Bausteine einer CPU und verstehen deren Zusammenspiel.
- können einfache Programme in einer hardwarenahen und effizienten Sprache wie C oder Rust schreiben.
- können ihre Programme mittels endlichen Automaten strukturieren.

## Aufgabenstellung

Entwickle eine virtuelle Maschine für das "[Little Computer](https://en.wikipedia.org/wiki/Little_Computer_3)"
[3a](https://www.cs.utexas.edu/users/fussell/cs310h/lectures/Lecture_10-310h.pdf)
oder
[3b](https://users.ece.utexas.edu/~patt/21s.460n/handouts/appA.pdf)
Instruction Set.

Um ein korrektes Funktionieren sicherzustellen, sollen Unit-Tests geschrieben werden. Ein Vorgehen
nach [TDD](https://de.wikipedia.org/wiki/Testgetriebene_Entwicklung) wird empfohlen.

Wichtig ist eine detaillierte inhaltliche Auseinandersetzung mit der Thematik.

Die im Unterricht behandelten theoretische Grundlagen sollen gründlich vertieft und gefestigt werden.

Die vollständige Implementierung der virtuellen Maschine ist zweitrangig.

### Programmiersprache

Die Wahl der Programmiersprache ist den Studierenden überlassen. Andere virtuelle Maschinen oder Interpreter wie
etwa [JVM](https://de.wikipedia.org/wiki/Java_Virtual_Machine), [CPython](https://en.wikipedia.org/wiki/CPython)
oder [Deno](https://en.wikipedia.org/wiki/Deno_(software)) sind aus Performancegründen meist in C, C++ oder Rust
geschrieben, weshalb die Wahl einer dieser Sprachen nahe liegt. Mögliche Alternativen sind andere kompilierte Sprachen
wie Go, C#, Java.

## Bericht

Der Bericht sollten folgende Teile enthalten:

- Einführung
    - Ausgangslage und Problemstellung
    - Zielsetzung
- Material und Methoden
- Ergebnisse
- Diskussion
- Quellen

Die Erläuterungen der Kapitel befinden sich im
Dokument "[Anleitung technischer Bericht](AnleitungTechnischerBericht.pdf)".

Umfang: ca 2500 Wörter.

## Bewertung

Folgende Kapitel werden mit je 10 Punkten bewertet:

- Einführung
- Material und Methoden
- Ergebnisse
- Diskussion

Die Note berechnet sich folgendermassen: Erreichte Punkte/40*5+1, gerundet auf 0.1.
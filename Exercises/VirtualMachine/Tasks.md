# Gruppenarbeit virtuelle Maschine

## Lernziele und Kompetenzen

Die Studierenden

- kennen die Bausteine einer CPU und verstehen deren Zusammenspiel.
- können einfache Programme in einer hardwarenahen und effizienten Sprache schreiben.
- können ihre Programme mittels endlichen Automaten strukturieren.

## Aufgabenstellung

Entwickle eine virtuelle Maschine für ein Subset des [RISC-V](https://en.wikipedia.org/wiki/RISC-V)
Instruction Set.

Wichtig ist eine inhaltliche Auseinandersetzung mit der Thematik, die vollständige Implementierung der virtuellen
Maschine ist zweitrangig.

### Programmiersprache

Die Wahl der Programmiersprache ist den Studierenden überlassen. Andere virtuelle Maschinen oder Interpreter wie
etwa [JVM](https://de.wikipedia.org/wiki/Java_Virtual_Machine), [CPython](https://en.wikipedia.org/wiki/CPython)
oder [Node](https://de.wikipedia.org/wiki/Node.js) sind aus Performancegründen meist in C oder C++ geschrieben, bei
neueren Projekten werden etwa Rust ([Deno](https://deno.com/)) oder Zig ([Bun](https://bun.sh/)) verwendet.

Diese Sprachen sind optimiert für performance-kritische Anwendungen. Mögliche Alternativen sind andere
kompilierte Sprachen wie Go, C# oder Java.

### Implementierung

Implementiere folgende Bauteile einer CPU nach der Theorie:

- Speicher: Program Counter, Register und RAM
- Decoder
- ALU

Schreibe für die einzelnen Bauteile _vor_ der Implementierung einen Unit-Test.

Beschränke dich bei der Implementierung auf die folgenden Instruktionen aus dem RV32I (Base integer instruction set,
32bit) Befehlssatz:

| Name          | MNEMONIC | Format            |
|---------------|----------|-------------------|
| ADD           | `add`    | Register/register |
| ADD Immediate | `addi`   | Immediate         |
| XOR Immediate | `xori`   | Immediate         |
| AND           | `and`    | Register/register |
| Branch EQual  | `beq`    | SB                |
| Load Byte     | `lb`     | Immediate         |
| Store Byte    | `sb`     | Immediate         |

Verarbeite die Instruktionen im binären Format. Konsultiere dazu die 
[offizielle Spezifikation](unpriv-isa-asciidoc.pdf) und [diese Übersichtsseite](https://msyksphinz-self.github.io/riscv-isadoc/html/index.html).

## Bericht

Der Bericht sollten folgende Teile enthalten:

- Einleitung
- Hauptteil
- Diskussion
- Empfehlungen und Ausblick

Die Erläuterungen der Kapitel befinden sich im
Dokument "[Anleitung technischer Bericht](AnleitungTechnischerBericht.pdf)".

Sämtliche Aussagen müssen mit belastbaren Quellen belegt werden.

Bericht und Code sollen zusammen in einem Github Repository verwaltet werden.

Umfang: ca 1000 Wörter / 4 Normseiten

## Bewertung

Folgende Kapitel werden mit je 10 Punkten bewertet:

- Einführung
- Hauptteil
- Diskussion
- Empfehlung und Ausblick

Die Note berechnet sich folgendermassen: Erreichte Punkte/40*5+1, gerundet auf 0.1.

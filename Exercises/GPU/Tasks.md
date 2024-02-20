# Übung GPU und Machine Learning

## Lernziele

Die Studierenden

- kennen die aktuellen Entwicklungen in der Prozessorentwicklung.
- können aktuelle Entwicklungen kritisch hinterfragen und konkrete Handlungen im betrieblichen Handlungen ableiten
- kennen den Unterschied zwischen General Purpose CPUs und spezialisierten Co-Prozessoren wie GPU, DSP oder Neural
  Engine.

## Aufgabenstellung

Schaue die folgenden Videos, bzw lese die Artikel und beantworte jeweils die zugehörigen Fragen.

Diskutiere anschliessend deine Antworten mit einem Klassenkameraden.

Bearbeite zuerst die Aufgabe "Machine Learning" und anschliessend eine weitere Aufgabe deiner Wahl.

Zum Erreichen der Lernziele sollten zwei Aufgaben vollständig gelöst werden.

Die Antworten sollen in einem kurzen Bericht festgehalten werden.
Dieser Bericht ist am Schluss per E-Mail an den Dozenten einzureichen.
**Die Abgabe ist zwingend**, wird jedoch nicht bewertet.

Es werden folgende formellen Anforderungen gestellt:

- Dateiformat: [Markdown](https://www.markdownguide.org/) oder daraus [generiertes PDF](https://pandoc.org/).
- Diagramme: [PlantUML](https://plantuml.com/de/), [Mermaid](https://mermaid.js.org/) o.ä.

### Machine Learning und GPU

[Deep Learning](https://www.youtube.com/watch?v=l42lr8AlrHk)

- Welche grundlegenden Rechenoperationen sind für ML Anwendungen wichtig?
- Wieso können ML Anwendungen so stark parallelisiert werden?

[How GPU Computing Works | GTC 2021](https://www.youtube.com/watch?v=3l10o0DYJXg)

- Wie Unterscheiden sich GPUs von CPUs?
- Wie ermöglichen GPUs die hohe parallele Ausführung von Berechnungen?

### NVidia

[NVIDIA Made a CPU.. I’m Holding It. - Grace CPU/Hopper SuperChip @ Computex 2023](https://www.youtube.com/watch?v=It9D08W8Z7o)

- Welche CPU Architektur nutzen die Nvidia Grace CPUs?
- Wiese sind die Grace-Hopper "Superchips" schneller als herkömmliche CPU/GPU Kombinationen?
- Skizziere die Grace-Hopper Systemarchitektur!

### Cloud Computing

Informiere dich über den AWS Inferentia KI Beschleuniger:

- https://aws.amazon.com/de/machine-learning/inferentia/
- https://awsdocs-neuron.readthedocs-hosted.com/en/latest/general/arch/neuron-hardware/inferentia2.html

Beantworte folgende Fragen:

- Wie ist der AWS Inferentia2 aufgebaut?
- Für welche Rechenoperationen ist der AWS Inferentia2 optimiert?
- Wie unterscheiden sich die KI-Beschleuniger-Instanzen von herkömmlichen CPU-Instanzen?
- Wie sind die Preise für KI-Beschleuniger Instanzen?

### GPU Entwicklung

Löse das folgende Tutorial:

https://github.com/kopytjuk/cuda-tutorial/blob/master/sc11-cuda-c-basics.pdf

Stelle sicher, dass du über eine [kompatible Grafikkarte](https://en.wikipedia.org/wiki/CUDA#GPUs_supported) verfügst!
# Übung CPU - Lösungen

1. Blockschaltbild
    - Instruction Fetch: Lädt die Instruktionen aus dem Speicher
    - Branch Predictor: Untersucht die Instruktionen nach Sprüngen (Branches) und versucht, vorherzusagen, welcher
      Ausführungsweg ausgeführt wird. Dies, um die Pipeline möglichst mit den korrekten Instruktionen zu füllen.
    - ALU: Hier werden die Rechenoperationen ausgeführt. Diese CPU besitz vier Integer ALUs und zwei Floating Point
      ALUs.
    - L1 Instruction Cache: Hier werden die geladenen Instruktionen zwischengespeichert. Wenn sie erneut geladen werden,
      werden sie aus dem schnellen Cache geladen anstatt aus dem langsamen Speicher (RAM).
2. Addition
    1. Die Instruktion wird in das Instruction Register geladen. (Instruction Fetch)
    2. Die Instruktion wird Decodiert und die nötigen Funktionseinheiten der CPU angesteuert.
       Dies beinhaltet für diese Instruktion die Integer-ALU sowie die Register, die die Daten beinhalten.
    3. Die Instruktion wird ausgeführt und das Resultat in den Registern gespeichert.
3. Es gibt verschiedene Hinweise:
    - Die Instruktionen sind alle gleich lang: 12-Bit Opcode
    - Die Instruktionen werden fast alle in einem Takt abgeschlossen
    - Lade- und Speicher-Instruktionen sind separat von den restlichen Instruktionen.
4.
    - Bei einem SoC befinden sich zusätzliche Controller auf dem selben Chip.
      Hier sind das GPU, Audio Code, Camera Interface, Video Engine, Display Engine, TV Encoder/Decoder etc
    - Neben diversen Controllern für I/O (Connectivity und User Interface) fallen v.a. die vielen Audio und Video
      Controller auf. Dies legt den Schluss nahe, dass es sich dabei um ein Soc für Multimedia-Applikationen handelt,
      wie es auf Single Board Computern wie etwa Raspberry PI verwendet wird oder in Laptops.
      SoC für Tablets oder Smartphones hätten vermutlich noch zusätzliche Beschleuniger für Kommunikationsprotokolle und
      vermutlich keinen TV (De)Coder
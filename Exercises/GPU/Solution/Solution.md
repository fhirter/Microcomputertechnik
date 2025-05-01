# GPU Lösungen

## Cloud Computing

Der Inferentia v2 ist für Machine Learning-Anwendungen konzipiert und basiert auf der "NeuronCore-v2" Architektur.

![Inferentia2.jpg](Inferentia2.jpg)

Auf dem Inferentia Chip befinden sich 32GB sogennantes High Bandwith Memory (HBM) mit 820GB/s Datenübertragungsrate, 
was mehr als 10x schneller ist als DDR4 RAM.

Zusätzlich verfügen die beiden NeuronCores je über einen eigenen SRAM, um eine sehr hohe 
Speicherzugriffsgeschwindigkeit zu erreichen. Bei den v3 NeuronCores ist das on-chip SRAM mit 28MB angeben, für die 
v2 ist keine Angabe auffindbar.

Compute: Two NeuronCore-v2 delivering 380 INT8 TOPS, 190 FP16/BF16/cFP8/TF32 TFLOPS, and 47.5 FP32 TFLOP.

Schnittstelle: NeuronLink mit 384 GB/s Datenübertragungsrate.

Die Trainium Chips sind den Inferentia sehr ähnlich, verfügen aber über vier NeuronLink-v2 Schnittstellen.

![img.png](NeuronCoreV2.png)
https://aws.amazon.com/de/blogs/machine-learning/aws-inferentia2-builds-on-aws-inferentia1-by-delivering-4x-higher-throughput-and-10x-lower-latency/


AWS Trainium Architecture
: https://awsdocs-neuron.readthedocs-hosted.com/en/latest/general/arch/neuron-hardware/trainium.html


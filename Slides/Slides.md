<!-- headingDivider: 4 -->
<style>
img {
  display: block;
  margin: 0 auto;
}
</style>

# Microcomputertechnik

## Software

![img.png](Tiobe0124.png)

---

![img.png](Thompson_Ritchie.png)

Ken Thompson, Dennis Ritchie

### C Keywords (Auswahl)

```
bool (C23)   extern        sizeof         default     return
false (C23)  float         static         do          volatile
break        for           struct         double      short
case         goto          switch         else        signed
char         if            true (C23)     unsigned    register
const        int           typedef        void        union
continue     long                       
```

### Python Keywords

```
False 	     await        else         import        pass
None 	     break        except       in            raise
True 	     class        finally      is            return
and          continue     for          lambda        try
as           def          from         nonlocal      while
assert 	     del          global       not           with
async 	     elif         if           or            yield
```

### Go Keywords

```
break        default      func         interface    select
case         defer        go           map          struct
chan         else         goto         package      switch
const        fallthrough  if           range        type
continue     for          import       return       var
```

https://go.dev/ref/spec#Keywords

## Aufbau und Funktion eines Microprozessors

![w:500px](Microprocessor.png)

https://erik-engheim.medium.com/how-does-a-microprocessor-run-a-program-11744ab47d04

### AVR Architektur Blockschaltbild

![img.png](AVR_Architecture.png)

### 1971: Intel 4004

![w:600px](Intel4004.png)

### AMD Threadripper

![w:600px](Ryzen_Threadripper_III.png)

### von Neumann Architektur

![img.png](vonNeumannArchitecture.png)

### Harvard Architektur

![w:600px](HarvardArchitecture.png)

### Fetch - Decode - Execute

![w:800px](Cortex_M4_Pipeline.png)

### Arithmetic Logic Unit (ALU)

![w:800px](ALU.png)

---

Mindestens:

* Addition (ADD)
* Negation (NOT)
* Konjunktion (AND)

Zusätzlich (Auswahl):

* Subtraktion
* Vergleich
* Multiplikationen / Division
* Oder
* Shift / Rotation

## Instruction Set

![img.png](MIPS21_OPCode.png)

http://lyons42.com/AVR/Opcodes/AVRAllOpcodes.html

### A64 Instruction Set

![img.png](A64_instruction_set_I.png)

--- 

![img.png](A64_instruction_set_II.png)

---

![img_2.png](A64_instruction_set_III.png)

---

![img.png](A64_instruction_set_IV.png)

### Assembler

```asm
mov a, 10000 ; Grenzwert der Drehzahl
mov b, 30    ; Grenzwert der Temperatur
mov O,1      ; Abschaltsignal

:loop          ; Markierung im Programmfluss (keine Instruktion, wird vom Assembler für Sprungadressen verwendet)
in d,PORT1   ; einlesen der aktuellen drehzahl-Werte
in t,PORT2   ; einlesen der aktuellen temp-Werte

:drehcheck
cmp d,a      ; prüfe die Drehzahl
jg  tempcheck; wenn Grenzwert nicht erreicht, springe zu :tempcheck
out PORT3,O  ; Grenzwert erreicht! setze Abschaltsignal

:tempcheck
cmp t,b      ; prüfe die Temperatur
jg  loop     ; wenn Grenzwert nicht erreicht, springe zu :loop
out PORT3,O  ; Grenzwert erreicht! setze Abschaltsignal

jmp loop     ;unbedingter Sprung zur Marke :loop (Endlosschleife)
```

https://de.wikipedia.org/wiki/Echtzeitsystem

## SoC vs Microprocessor vs Microcontroller

### Microcontroller: ATmega328P

![img.png](img.png)

### System on Chip (SoC)

![img.png](System_on_chip.png)

--- 

![img.png](Samsung_Galaxy_S3.png)
Samsung Galaxy S3

---

![w:600px](Apple_M1.png)
Apple M1

### Microprocessor: AMD Ryzen Threadripper

![img_1.png](Ryzen_Threadripper_I.png)

---

![img_1.png](Ryzen_Threadripper_II.png)

### Advanced RISC Machine (ARM)

> "Arm licenses processor designs to semiconductor companies that incorporate the technology into their computer chips.
> Licensees pay an up-front fee to gain access to our technology, and a royalty on every chip that uses one of our technology designs.
> Typically, the royalty is based on the selling price of the chip." 

(https://group.softbank/en/ir/financials/annual_reports/2021/message/segars, 08.01.2024)

---

![img_1.png](arm_company_highlights.png)

## RISC vs CISC

### Reduced Instruction Set Computer (RISC)

- Opcode hat eine feste Länge
- Meistens 1 Takt pro Operation
- Load/Store Architektur: Separate Lade und Speicher-Befehle
- Hohe Anzahl an Registern für Zwischenresultate
- Oft Harvard-Architektur
- Grundsätzlich: Einfachere Architektur, einfacher für Compiler
- Alles andere: CISC

### Pipelining

![img_1.png](Pipelining.png)

---

![img_1.png](Apple_M1_stages.png)
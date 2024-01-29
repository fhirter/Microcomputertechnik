<!-- headingDivider: 4 -->
<style>
img {
  display: block;
  margin: 0 auto;
}
</style>

# Microcomputertechnik

## Überblick

![img.png](images/ueberblick.png)

## Software

![img.png](images/Tiobe0124.png)

---

![img.png](images/Thompson_Ritchie.png)

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

## Hochsprache zu Maschinencode

### Rust

```rust
pub fn square(num: i32) -> i32 {
    num * num
}
```

### Assembler

```asm
square:
        push    {r7, lr}
        sub     sp, #8
        smull   r1, r0, r0, r0
        mov     r2, r1
        str     r2, [sp, #4]
        cmp.w   r0, r1, asr #31
        bne     .LBB0_2
        b       .LBB0_1
.LBB0_1:
        ldr     r0, [sp, #4]
        add     sp, #8
        pop     {r7, pc}
.LBB0_2:
        ldr     r0, .LCPI0_0
.LPC0_0:
        add     r0, pc
        ldr     r2, .LCPI0_1
.LPC0_1:
        add     r2, pc
        movs    r1, #33
        bl      core::panicking::panic
        .inst.n 0xdefe
.LCPI0_0:
        .long   str.0-(.LPC0_0+4)
.LCPI0_1:
        .long   .L__unnamed_1-(.LPC0_1+4)
.L__unnamed_2:
        .ascii  "/app/example.rs"
.L__unnamed_1:
        .long   .L__unnamed_2
        .asciz  "\017\000\000\000\013\000\000\000\005\000\000"

str.0:
        .ascii  "attempt to multiply with overflow"
```
[godbolt.org](https://godbolt.org/e)



## Aufbau und Funktion eines Microprozessors

![w:500px](images/Microprocessor.png)

https://erik-engheim.medium.com/how-does-a-microprocessor-run-a-program-11744ab47d04

### AVR Architektur Blockschaltbild

![img.png](images/AVR_Architecture.png)

### 1971: Intel 4004

![w:600px](images/Intel4004.png)

### AMD Threadripper

![w:600px](images/Ryzen_Threadripper_III.png)

### Apple M1

![img_1.png](images/Apple_M1_stages.png)

### ARM Cortex A67

![w:600px](images/cortex_a76.png)

### von Neumann Architektur

![img.png](images/vonNeumannArchitecture.png)

### Harvard Architektur

![w:600px](images/HarvardArchitecture.png)

### Fetch - Decode - Execute

![w:800px](images/Cortex_M4_Pipeline.png)

### Arithmetic Logic Unit (ALU)

![w:800px](images/ALU.png)

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

![img.png](images/MIPS21_OPCode.png)

http://lyons42.com/AVR/Opcodes/AVRAllOpcodes.html

### A64 Instruction Set

![img.png](images/A64_instruction_set_I.png)

--- 

![img.png](images/A64_instruction_set_II.png)

---

![img_2.png](images/A64_instruction_set_III.png)

---

![img.png](images/A64_instruction_set_IV.png)

### Reduced Instruction Set Computer (RISC)

- Opcode hat eine feste Länge
- Meistens 1 Takt pro Operation
- Load/Store Architektur: Separate Lade und Speicher-Befehle
- Hohe Anzahl an Registern für Zwischenresultate
- Oft Harvard-Architektur
- Grundsätzlich: Einfachere Architektur, einfacher für Compiler
- Alles andere: **CISC**


## SoC vs Microprocessor vs Microcontroller

### Microcontroller: ATmega328P

![img.png](images/img.png)

### System on Chip (SoC)

![img.png](images/System_on_chip.png)

--- 

![img.png](images/Samsung_Galaxy_S3.png)
Samsung Galaxy S3

---

![w:600px](images/Apple_M1.png)
Apple M1

### Microprocessor: AMD Ryzen Threadripper

![img_1.png](images/Ryzen_Threadripper_I.png)

---

![img_1.png](images/Ryzen_Threadripper_II.png)

### Advanced RISC Machine (ARM)

> "Arm licenses processor designs to semiconductor companies that incorporate the technology into their computer chips.
> Licensees pay an up-front fee to gain access to our technology, and a royalty on every chip that uses one of our technology designs.
> Typically, the royalty is based on the selling price of the chip." 

(https://group.softbank/en/ir/financials/annual_reports/2021/message/segars, 08.01.2024)

---

![img_1.png](images/arm_company_highlights.png)

## Moore's Law

![w:600px](images/MooresLaw.png)

### Strukturgrösse

![img.png](images/struckturgroesse.png)

### TSMC

![img.png](images/TSMC_process.png)

## Pipelining

![img_1.png](images/Pipelining.png)


## Speicher

### Cache

![img.png](images/cache.png)
(Silberschatz, 2019)

---

![img.png](images/storage_hierarchy.png)
(Silberschatz, 2019)

--- 

![img.png](images/storage_characteristics.png)
(Silberschatz, 2019)

## Quellen

Silberschatz, 2019
: A.Silberschatz, P.B.Galvin, G. Gagne (2019): Operating System Concepts, Global Edition, Wiley
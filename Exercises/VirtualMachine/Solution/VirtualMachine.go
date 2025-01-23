package main

type WordSize uint16

type ConditionCodes struct {
	zero     bool
	negative bool
	positive bool
}

var instruction_register WordSize
var programCounter WordSize

var registers = [8]WordSize{}

var memory = [2 ^ 16]WordSize{}

var address_bus WordSize
var data_bus WordSize

func main() {
	// fetch (IR, PC, Memory, Data Bus, Address Bus)
	// decode (IR, Decoder, Control Lines)
	// execute (ALU, Register, Memory)
}

func fetch() {
	// load instruction from memory
	instruction_register = memory[programCounter]
	programCounter++
}

func decode() {

}

func execute() {
	var alu = ALU()
	alu.fAND()
}

// instructions (LC-3a)
// operate
const (
	ADD = 0b0000 // 0x0
	AND = 0b0101 // 0x5
	NOT = 0b1001
	// data movement
	LD  = 0b0010
	LDI = 0b1010
	LDR = 0b0110
	LEA = 0b1110
	ST  = 0b0011
	STR = 0b0111
	STI = 0b1011
	// control
	BR = 0b0000
	//JSR = /JSRR
	JMP = 0b1100
	//RTI
	TRAP = 0b1111
)

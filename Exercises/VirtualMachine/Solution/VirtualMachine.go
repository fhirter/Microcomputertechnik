package main

func main() {
	// fetch
	// decode
	// execute
}

type WordSize uint16

func fNOT(srcValue WordSize) WordSize {
	return ^srcValue
}

//func execute(operation)

var instruction_register WordSize
var program_counter WordSize

type Condition_Codes struct {
	zero     bool
	negative bool
	positive bool
}

var condition_codes Condition_Codes

var registers = [8]WordSize{}

// memory

// instructions
// operate
const (
	ADD = 0b000
	AND = 0b0101
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
	BR = 0000
	//JSR = /JSRR
	JMP = 1100
	//RTI
	TRAP = 0b1111
)
package main

import "testing"

var alu = ALU{}

type OpCodes struct {
	add  int8
	addi int8
	xori int8
	and  int8
	beq  int8
	lb   int8
	sb   int8
}

var opCodes = OpCodes{
	add:  1,
	addi: 2,
	xori: 3,
	and:  4,
	beq:  5,
	lb:   6,
	sb:   7,
}

func TestFADD(t *testing.T) {
	var srcValue1 WordSize = 0x1
	var srcValue2 WordSize = 0x1
	var expected WordSize = 0x2

	given := alu.execute(opCodes.add, srcValue1, srcValue2)

	if given != expected {
		t.Fatalf(`ADD is not working as expected. given: %b, expected: %b`, given, expected)
	}
}

func TestFAND(t *testing.T) {
	var srcValue1 WordSize = 0b0000000000000010
	var srcValue2 WordSize = 0b0000000000000011
	var expected WordSize = 0b0000000000000010

	given := alu.execute(opCodes.and, srcValue1, srcValue2)

	if given != expected {
		t.Fatalf(`AND is not working as expected. given: %b, expected: %b`, given, expected)
	}
}

func TestFLD(t *testing.T) {
}
func TestFLDI(t *testing.T) {

}
func TestFLDR(t *testing.T) {

}
func TestFLEA(t *testing.T) {

}
func TestFST(t *testing.T) {

}
func TestFSTR(t *testing.T) {

}
func TestFSTI(t *testing.T) {

}
func TestFBR(t *testing.T) {

}
func TestJMP(t *testing.T) {

}

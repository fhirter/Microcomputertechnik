package main

import "testing"

func TestFNOT(t *testing.T) {
	var srcValue WordSize = 0b0101010101010101
	var expected WordSize = 0b1010101010101010

	given := fNOT(srcValue)

	if given != expected {
		t.Fatalf(`NOT is not working as expected. given: %b, expected: %b`, given, expected)
	}
}

func TestFADD(t *testing.T) {
	var srcValue1 WordSize = 0b0000000000000001
	var srcValue2 WordSize = 0b0000000000000001
	var expected WordSize = 0b0000000000000010

	given := fADD(srcValue1, srcValue2)

	if given != expected {
		t.Fatalf(`ADD is not working as expected. given: %b, expected: %b`, given, expected)
	}
}

func TestFAND(t *testing.T) {
	var srcValue1 WordSize = 0b0000000000000010
	var srcValue2 WordSize = 0b0000000000000011
	var expected WordSize = 0b0000000000000010

	given := fAND(srcValue1, srcValue2)

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

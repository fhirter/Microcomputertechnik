package main

import "testing"

func TestDecode(t *testing.T) {
	var instruction InstructionSize = 0b0
	decodeInstruction(instruction)
}

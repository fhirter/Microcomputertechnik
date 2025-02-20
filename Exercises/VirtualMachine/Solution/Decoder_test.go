package main

import "testing"

func TestDecodeAdd(t *testing.T) {
	var instruction InstructionSize = 0b....
	var operation = decodeInstruction(instruction)

	var expectedOperation opCode = OpCodeValues.add

	if operation != expectedOperation {
		t.Fatalf(`ADD is not decoded correctly. given: %b, expected: %b`, operation, expectedOperation)
	}
}

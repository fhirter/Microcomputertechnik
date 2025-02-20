package main

func decodeInstruction(instruction InstructionSize) opCode {
	var opcode = instruction & 0b111111         // 0 - 6
	var funct3 = instruction & (0b111 << 12)    // 12 - 14
	var func7 = instruction & (0b1111111 << 25) // 25 - 31

	return opCode(opcode)
}

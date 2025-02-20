package main

type ALU struct{}

func (a ALU) execute(opCode opCode, value1 WordSize, value2 WordSize) WordSize {

	switch opCode {
	case 1:
		return a.fADD(value1, value2)

	case 4:
		return a.fAND(value1, value2)
	}
	return 0
}

func (a ALU) FNot(srcValue WordSize) WordSize {
	return ^srcValue
}

func (a ALU) fADD(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 + srcValue2
}

func (a ALU) fAND(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 & srcValue2
}

package main

type ALU struct{}

func (a ALU) FNot(srcValue WordSize) WordSize {
	return ^srcValue
}

func (a ALU) fADD(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 + srcValue2
}

func (a ALU) fAND(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 & srcValue2
}

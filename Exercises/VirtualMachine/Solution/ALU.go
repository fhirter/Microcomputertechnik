package main

type ALU struct {
	conditionCodes ConditionCodes
}

func (a ALU) fNOT(srcValue WordSize) WordSize {
	return ^srcValue
}

func (a ALU) fADD(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 + srcValue2
}

func (a ALU) fAND(srcValue1 WordSize, srcValue2 WordSize) WordSize {
	return srcValue1 & srcValue2
}

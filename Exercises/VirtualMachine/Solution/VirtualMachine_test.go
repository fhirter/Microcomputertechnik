package main

import "testing"

func TestFNOT(t *testing.T) {
	var srcValue uint16 = 0b0101010101010101
	var expectedValue uint16 = 0b1010101010101010

	dstValue := fNOT(srcValue)

	if dstValue != expectedValue {
		t.Fatalf(`NOT is not working as expected. given: %b, expected: %b`, dstValue, expectedValue)
	}
}

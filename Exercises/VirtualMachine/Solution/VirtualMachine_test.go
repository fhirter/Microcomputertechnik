package main

import "testing"

func TestFNOT(t *testing.T) {
	var srcValue WordSize = 0b0101010101010101
	var expectedValue WordSize = 0b1010101010101010

	dstValue := fNOT(srcValue)

	if dstValue != expectedValue {
		t.Fatalf(`NOT is not working as expected. given: %b, expected: %b`, dstValue, expectedValue)
	}
}

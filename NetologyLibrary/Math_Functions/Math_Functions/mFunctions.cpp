#include "mFunctions.h"

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mult(int a, int b) {
	return a * b;
}
int divn(int a, int b) {
	return a / b;
}
int exp(int a, int b) {
	int value = 1;
	if (b == 0) {
		return 1;
	}
	else {
	
		for (int i = 0; i < b; i++) {
			value *= a;
		}
		return value;

	}
}
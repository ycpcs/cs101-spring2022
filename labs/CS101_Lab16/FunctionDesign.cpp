#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function prototypes go here.
int addInts(int a, int b);

int main(void) {
	// Tests for each function go here
	assert(addInts(4, 5) == 9);
	assert(addInts(0, 11) == 11);
	assert(addInts(4, -19) == -15);
	assert(addInts(-4, -9) == -13);

	printf("All tests passed!\n");
	return 0;
}

int addInts(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}

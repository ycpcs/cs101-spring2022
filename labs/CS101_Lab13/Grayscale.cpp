#include <stdio.h>
#include "Image.h"

// Arrays to store image color component data.
// Note that it is normally not a good practice to define
// variables/arrays in the global scope.  However, because
// these arrays have a large number of elements, they
// are too large to define within a function (such as main)
// on some systems.
int red[WIDTH][HEIGHT];
int green[WIDTH][HEIGHT];
int blue[WIDTH][HEIGHT];

int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);

	// TODO: transform data

	WriteImage("grayscale.bmp", red, green, blue);
	printf("Done writing image\n");

	return 0;
}

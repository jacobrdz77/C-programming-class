#include <stdio.h>

int main() {

    unsigned char a, r, g, b;
    int tempA, tempR, tempG, tempB;
    printf("Enter values for a, r, g, and b: ");
    scanf("%d %d %d %d", &tempA, &tempR, &tempG, &tempB);

    a = (char)tempA;
    r = (char)tempR;
    g = (char)tempG;
    b = (char)tempB;

    // Combine into one variable using bitwise operations
    // color has 4 bytes (32 bits)
    // each color has 1 byte (8 bits)
    // start at 24 and fill up the space with each value in the right space;
    unsigned int color = (a << 24) | (r << 16) | (g << 8) | b;

    // Output as a hexadecimal
    printf("Color value: %#x", color);

    return 0;
}


/*
Color Specification

ARGB color consists of 4 components - alpha transparency, red, green and blue. The four components are encoded as a 32-bit number, with each component occupying 8 bits. In hexadecimal notation, it is AARRGGBB, where AA, RR, GG and BB are the alpha transparency, red, green and blue components.

Each component ranges from 00 - FF (0 - 255), representing its intensity. For example, pure red color is 00FF0000, pure green color is 0000FF00, and pure blue color is 000000FF. White color is 00FFFFFF, and black color is 00000000.

Write a program that has the user input decimal values from 0-255 into each of these variables:

unsigned char a, r, g, b;
Combine these variables using only bitwise operations into a single value:

unsigned int color;
Output this value as a hexadecimal, to the console.

Example Output Results:

Enter values for a, r, g, and b:39 59 120 200
Color value: 0x273b78c8
*/
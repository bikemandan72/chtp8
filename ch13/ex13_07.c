/*
13.7 (Smallest of Three Numbers)
Write a program that defines and uses macro MINIMUM3 to determine the smallest of three
numeric values. Macro MINIMUM3 should use macro MINIMUM2 defined in Exercise 13.6 to
determine the smallest number. Input the values from the keyboard.
*/
#include <stdio.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))
#define MINIMUM3(x, y, z) (MINIMUM2(x,y) < (z) ? MINIMUM2(x, y) : (z))

int main(int argc, char *argv[])
{
    int a = 10, b = -7, c = 20;
    puts("Enter three integers:");
    scanf("%d%d%d", &a, &b, &c);
    printf("Minimum of %d, %d and %d is %d\n", a, b, c, MINIMUM3(a, b, c));
    return 0;
}
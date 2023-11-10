/*
13.6 (Smallest of Two Numbers)
Write a program that defines and uses macro MINIMUM2 to determine the smallest of two
numeric values. Input the values from the keyboard.
*/
#include <stdio.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))

int main(int argc, char *argv[])
{
    int a = 10, b = -7;
    puts("Enter two integers:");
    scanf("%d%d", &a, &b);
    printf("Minimum of %d and %d is %d\n", a, b, MINIMUM2(a, b));
    return 0;
}
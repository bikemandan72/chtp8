/*
13.4 (Volume of a Sphere)
Write a program that defines a macro with one argument to compute the volume of a sphere. The program should compute the volume for spheres of radius 1 to 10 and
print the results in tabular format. The formula for the volume of a sphere is
(4.0 / 3) * π * r^3 where π is 3.14159 .
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define SPHERE_VOLUME(R) (4.0/3*PI*pow((R), 3))

int main (int argc, char *argv[])
{
	double r = 0.3;
	puts("Enter sphere radius:");
	scanf("%lf", &r);
	printf("Volume of a sphere with radius %lf is %lf\n.", r, SPHERE_VOLUME(r));
	return 0;
}

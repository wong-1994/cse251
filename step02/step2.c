#include <stdio.h>
#include <math.h>
/*
 * Name: Jian
 *
 * This is my first CSE 251 C program
 */
int main()
{
    double volume, diameter, hypot;
    int games;
    double radius = 7.88;
    double height = 12.231;
    int wins = 11;
    int losses = 2;
    double near = 10;
    double far = 22.5;
    double bottleVolume = 1700; // Milliliters
    double cupVolume = 350; // Milliliters
    int numCups;

    volume = radius * radius * M_PI * height;
    games = wins + losses;
    hypot = sqrt(near * near + far * far);
    numCups = (int)(bottleVolume / cupVolume);

    printf("My first C program\n");
    printf("The volume of the cylinder is %f\n", volume);
    printf("The game has been playde is %d\n", games);
    printf("The hypotenuse of the triangle is %f\n", hypot);
    printf("Number of cups: %d\n", numCups);

}
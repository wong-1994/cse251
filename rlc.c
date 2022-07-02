#include <stdio.h>
#include <math.h>

int main()
{
    float c, l, C, L, w, f;
    printf("Input Capacitance (microfarads):");
    scanf("%f", &c);
    printf("Input Inductance (millihenrys):");
    scanf("%f", &l);

    C = c / 1000000;
    L = l / 1000;
    w = 1 / sqrt(C * L);
    f = w / (M_PI * 2);

    printf("Resonant Frequency is %6.3f\n", f);
}
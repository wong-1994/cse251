#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double a, b, x, delta, result, output, decrease;
    int i;
    int n = 10;
    bool flg;

    do
    {
        printf("Enter a value for a: ");
        scanf("%lf", &a);
        printf("Enter a value for b: ");
        scanf("%lf", &b);
        if (a >= b)
            printf("Please make sure a is less than b\n");
    } while (a >= b);

    printf("Integral evaluation\n");
    while (n <= 100000)
    {
        delta = (b - a) / n;
        output = 0;
        for (i = 1; i <= n; i++)
        {
            x = a + ((double)i - 0.5) * delta;
            if (x == 0)
                output = output + 1;
            else
                output = output + delta * sin(M_PI * x) / (M_PI * x);
        }
        printf("%d: %11.9lf ", n, output);
        if (n == 10)
        {
            result = output;
            printf("\n");
        }
        else
        {
            decrease = fabs(result - output);
            result = output;
            printf("%le\n", decrease);
            if (decrease < 1e-10)
                break;
        }
        n++;
    }
}
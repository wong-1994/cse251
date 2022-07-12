#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int i = 1;
    int f = 3;
    int fac = 1;
    int inValue;

    while (true)
    {
        printf("Number  to compute the factorial of: ");
        scanf("%d", &f);
        inValue = f;

        if (f < 0)
            break;    
        if (f == 0)
            fac = 1;
        while (f > 0)
        {
            fac = fac * f;
            f--;
        }
        printf("%d! = %d\n", inValue, fac);
    }
 
}
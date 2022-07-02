#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float c, l, C, L, w, f;
    bool valid = true;

    printf("Input Capacitance (microfarads):");
    scanf("%f", &c);
    if (c<0)
    {
        printf("You moron, you entered a negative capacitance!\n");
        valid = false;
    }
        
    else if (c==0)
    {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }   
    else
        printf("Okay, I guess that's reasonable\n");

    printf("Input Inductance (millihenrys):");
    scanf("%f", &l);
    if (l<0)
    {
        printf("You moron, you entered a negative inductance!\n");
        valid = false;
    }
    else if (l==0)
    {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }   
    else
        printf("Okay, I guess that's reasonable\n");
    
    if (valid) 
    {
        C = c / 1000000;
        L = l / 1000;
        w = 1 / sqrt(C * L);
        f = w / (M_PI * 2);
        printf("Resonant Frequency is %6.3f\n", f);
        if(f>20)
        {
            if(f<20000)
                printf("This frequency is one I can hear\n");
        }
    }
}
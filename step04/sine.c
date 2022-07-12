#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    double angle;
    int numSteps;
    double maxAngle = M_PI * 2;
    int i, j, numSpaces;
    float sinVal;

    do
    {
        printf("Input the number of steps: ");
        scanf("%d", &numSteps);
    } while (numSteps < 2);

    for (i = 0; i <= numSteps; i++)
    {
        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
        numSpaces = 30 + sinVal * 30;
        printf("%3d: %5.2f ", i, angle);
        for (j = 0; j < numSpaces; j++)
        {
            printf(" ");
        }
        if (fabs(cos(angle)) < 0.1)
            printf("*\n");
        else if (cos(angle) < 0)
            printf("/\n");
        else if (cos(angle) > 0)
            printf("\\\n");
    }
}
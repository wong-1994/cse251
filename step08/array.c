#include <stdio.h>

#define NumMovies 10
#define MaxGrosses 5

int main()
{
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622, 
                                3156594, 1629735, 2659234, 2028036, 510768};
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                            "Just Go With it", "Gnomeo and Juliet", "Drive Angry",
                            "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                            "True Grit"};
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 5000000};
    double highestGrosses[MaxGrosses] = {0, 0, 0, 0, 0};
    int highestGrossesIndex[MaxGrosses] = {0, 0, 0, 0, 0};
    double sum;
    int i;
    int j;
    int highestGrossIndex = 0;
    double highestGross = 0;
    

    sum = 0;
    for(i=0; i<NumMovies; i++)
    {
        if(gross[i]>highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
        printf("Movie %d, %s: %.0f\n", i+1, names[i], gross[i]);
        sum += gross[i];
    
        if(gross[i]<maxGross[0] && gross[i]>highestGrosses[0])
        {
            highestGrossesIndex[0] = i;
            highestGrosses[0] = gross[highestGrossesIndex[i]];
        }
        for (j=1; j<MaxGrosses; j++)
        {
            if(gross[i]<maxGross[j] && gross[i]>=maxGross[j-1] && gross[i]>highestGrosses[j])
            {
                highestGrossesIndex[j] = i;
                highestGrosses[j] = gross[highestGrossesIndex[j]];
            }
        }
    }
    printf("Total gross for these films was %.0f\n", sum);
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);
    
    for(j=0; j<MaxGrosses; j++)
    {
        if(highestGrosses[j]==0)
        {
            printf("No film made less than %.0f\n", maxGross[j]);
        }
        else
        {
            printf("The highest gross less than %.0f is %s at %.0f\n", maxGross[j], names[highestGrossesIndex[j]], gross[highestGrossesIndex[j]]);
        }
    }
}
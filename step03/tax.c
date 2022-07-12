#include <stdio.h>
#include <stdlib.h>

int main()
{
    double annualIncome, stdDeduction, totalDeduction, taxableIncome, taxes;
    int filingStatus, numDependents, numChildren;


    printf("Enter your annual income:");
    scanf("%lf", &annualIncome);
    if (annualIncome<9350)
    {
        printf("0\n");
        exit(1);
    }

    printf("What is your filing status?\n1) single\n2) married filing jointly\n3) married filing separately");
    printf("Please enter a number:\n");
    scanf("%d", &filingStatus);
    switch(filingStatus)
    {
        case 1:
            numDependents = 1;
            stdDeduction = 5700;
            break;
        case 2:
            stdDeduction = 11400;
            printf("How many children do you have?\n");
            scanf("%d", &numChildren);
            numDependents = 2 + numChildren;
            break;
        case 3:
            numDependents = 1;
            stdDeduction = 5700;
            break;
        default:
            printf("Invalid Input!!\n");
            exit(1);
    }      

    totalDeduction = 3650 * numDependents + stdDeduction;
    taxableIncome = annualIncome - totalDeduction;

    if (taxableIncome < 0)
        taxes = 0;
    else if (taxableIncome < 16750)
        taxes = 0.1 * taxableIncome;
    else if (taxableIncome < 68000)
        taxes = 1675 + 0.15 * (taxableIncome-16750);
    else if (taxableIncome < 137300)
        taxes = 9362.5 + 0.25 * (taxableIncome-68000);
    else
        taxes = 26687.5 + 0.28 * (taxableIncome-137300);

    printf("%6.2lf\n", taxes);
    
}

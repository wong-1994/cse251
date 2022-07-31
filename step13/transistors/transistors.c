#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
 */

int main()
{
    int i;
    Tran *trans;
    int numTrans = 0;
    bool ifadd;

    printf("transistors!\n");

    // Allocate space for one transistor
    trans = malloc(sizeof(Tran));
    numTrans = 1;

    // Input the transistor
    trans[0] = InputTransistor();

    // Input more transistor
    while (true)
    {
        ifadd = InputAddTran();
        if (ifadd == true)
        {
            // Increase the space by one transistor
            trans = realloc(trans, sizeof(Tran) * (numTrans + 1));
            numTrans++;

            // Add a new transistor
            trans[numTrans - 1] = InputTransistor();
        }
        else if (ifadd == false)
            break;
    }

    // Output the transistor
    printf("\nThe transistors:\n");
    for (i = 0; i < numTrans; i++)
    {
        DisplayTransistor(trans[i]);
    }

    // Free the memory
    free(trans);
}
#include <stdio.h>
#include <string.h>

#include "scheduler.h"

void DisplayOption()
{
    printf("1 - Insert a new event\n");
    printf("2 - Display all events\n");
    printf("3 - Now?\n");
    printf("4 - Delete expired\n");
    printf("0 - Exit\n");
    printf("Please select an option: ");
}

int InputOption()
{
    char buffer[100];
    int value = 0;

    do
    {
        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%d", &value);
    } while (!(value > 0 && value < 4));

    return value;
}
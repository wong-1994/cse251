#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"

int main()
{
    int option;

    DisplayOption();

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        InputEvent();
        break;
    case 0:
        return 0;
    
    default:
        break;
    } 
}
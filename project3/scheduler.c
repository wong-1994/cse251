#include <stdio.h>
#include <stdlib.h>

#include "scheduler.h"

int main()
{
    int option;

    DisplayOption();

    option = InputOption();
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
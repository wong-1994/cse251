#include <stdio.h>
#include <stdlib.h>
#define __USE_XOPEN
#include <time.h>

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

void DisplayEvent(Event *evt)
{   
    struct tm dateTM;

    dateTM = *localtime(&(evt->date));
    printf("%d/%d/%d\t", dateTM.tm_mon+1, dateTM.tm_mday, (dateTM.tm_year+1900));
    printf("\n");
}

void DisplayEvents(Schedule *schedule)
{
    int i;

    printf("\nSchedule:\n");
    for(i=0;  i<schedule->numEvents;  i++)
    {
        DisplayEvent(&schedule->events[i]);
    }

    printf("\n");
}
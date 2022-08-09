#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scheduler.h"

int main()
{
    int option;
    int i;
    int j;
    bool firstEvent = true;
    Schedule schedule;
    Event event;

    while(true)
    {
        DisplayOption();

        option = InputOption();
        if(option == 1)
        {
            if(firstEvent)
            {
                schedule.events = malloc(sizeof(Event));
                schedule.events[0] = InputEvent();
                schedule.numEvents = 1;
                firstEvent = false;
            }
            else
            {
                schedule.events = realloc(schedule.events, sizeof(schedule));
                event = InputEvent();
                for(i=schedule.numEvents-1; schedule.events[i].start<event.start; i--)
                {
                    schedule.events[i+1] = schedule.events[i]; 
                }
                schedule.events[i] = event;
                schedule.numEvents ++; 
            }
        }
        else if(option == 2)
        {
            DisplayEvents(&schedule);
        }
        else if(option == 0)
        {
            break;
        }
    }

    free(schedule.events);
}

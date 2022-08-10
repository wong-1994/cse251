#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define __USE_XOPEN
#include <time.h>

#include "scheduler.h"

int main()
{
    int option;
    int i;
    int j;
    bool firstEvent = true;
    Schedule *schedule;
    Event event;

    schedule = malloc(sizeof(Schedule));


    while(true)
    {
        DisplayOption();

        option = InputOption();
        if(option == 1)
        {
            if(firstEvent)
            {
                schedule->events = malloc(sizeof(Event));
                schedule->events[0] = InputEvent(schedule->events[0]);
                schedule->numEvents = 1;
                firstEvent = false;
            }
            else
            {
                schedule->events = realloc(schedule->events, sizeof(schedule) * (schedule->numEvents));
                event = InputEvent(event);
                for(i=schedule->numEvents-1; schedule->events[i].start<event.start; i--)
                {
                    schedule->events[i+1] = schedule->events[i]; 
                }
                schedule->events[i] = event;
                schedule->numEvents ++; 
            }
        }
        else if(option == 2)
        {
            DisplayEvents(schedule);
        }
        else if(option == 0)
        {
            break;
        }
    }

    free(schedule->events);
}

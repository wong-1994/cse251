#include <stdio.h>
#include <stdlib.h>

#include "RobotLib.h"

void OnMachineRequest(int machine);

/*
 * Name :        <insert name here>
 * Description : Robot scheduler program
 */

/*
 * Name :        main()
 * Description : Program entry point.
 */
struct Request
{
    int machine;
    struct Request *next;
};

struct Request *firstInLine = NULL;
struct Request *lastInLine = NULL;

int main()
{
    /*
     * This call starts the system running
     */
    printf("Robot System Startup\n");
    SimulatorStartup();

    SetMachineRequestHandler(OnMachineRequest);

    /*
     * This loop runs until we shut the simulator down
     * by closing the window it runs in.
     */
    while(IsSimulatorRunning())
    {
        if(!IsRobotBusy() && firstInLine != NULL)
        {
            RobotGoTo(firstInLine->machine);

            // Remove the first item from the queue
            struct Request *wasFirst = firstInLine;
            firstInLine = firstInLine->next;

            free(wasFirst);

            // Handle an empty queue 
            if(firstInLine == NULL)
                lastInLine = NULL;
        }

        if(IsRobotBusy())
        {
            ResetTimer();
        }

        if(GetTimer() > 3 && firstInLine == NULL)
        {
            RobotGoTo(0);
        }

    }

    /*
     * This call shuts down the robot system
     */
    printf("Robot System Shutdown\n");
    SimulatorShutdown();
    return 0;
}

void OnMachineRequest(int machine)
{
    printf("Robot request from machine %d\n", machine);
    struct Request *newRequest = malloc(sizeof(struct Request));
    newRequest->machine = machine;
    newRequest->next = NULL;

    if(lastInLine != NULL)
    {
        // This is the new last in the line
        lastInLine->next = newRequest;
        lastInLine = newRequest;
    }
    else
    {
        // The queue is empty, make this the first request
        firstInLine = newRequest;
    }

    // The new request is already the last in line
    lastInLine = newRequest;

    printf("There are %d pending requests\n", CountRequest());
   
}

int CountRequest()
{
    int cnt = 0;
    struct Request *request = firstInLine;

    while(request->next != NULL)
    {
        request = request->next;
        cnt ++;
    }

    return cnt;
}


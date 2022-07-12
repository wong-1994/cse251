#include <stdio.h>
#include <stdlib.h>

#include "ElevatorLib.h"

#define N 200
#define FloorSpeed 3.28
#define FloorTolerance 0.16

/*
 * Name :        <insert name here>
 * Description : Project 2 - The elevator controller
 */

/*
 * Name :        main()
 * Description : Program entry point.
 */
int main()
{
    /*
     * This call starts the elevator system running
     */
    printf("Elevator Startup\n");
    ElevatorStartup();

    bool goingUp = true;
    double desiredSpeed = 1;
    double power;
    double errors[N] = {0};
    double errorTotal = 0;
    int errorLoc = 0;

    SetBrake(false);
    SetMotorPower(1);
    ChangeLoading();
    /*
     * This loop runs until we shut the elevator system down
     * by closing the window it runs in.
     */
    while(IsElevatorRunning())
    {
        if(GetPosition() > 2*FloorSpacing+FloorTolerance && goingUp)
        {
            // We are above the third floor. Reverse direction
            goingUp = false;
            // SetMotorPower(-1);
            ChangeLoading();
            desiredSpeed = -1;
        }

        if(GetPosition() < FloorTolerance && !goingUp)
        {
            // We are below the first floor. Reverse direction
            // goingUp = true;
            // SetMotorPower(1);
            // ChangeLoading();
            // desiredSpeed = 1;
            SetMotorPower(0);
            SetBrake(true);
        }
        
        if(GetPosition()>1.5*FloorSpacing && goingUp)
        {
            desiredSpeed = (2*FloorSpacing - GetPosition()) / (FloorSpacing / 2); 
        }

        if(GetPosition()<0.5*FloorSpacing && !goingUp)
        {
            desiredSpeed = (-GetPosition()) / (FloorSpacing / 2); 
        }

        if(GetCallLight(1, true))
        {
            // Button has been pressed
            goingUp = true;
            SetBrake(false);
            ChangeLoading();
            desiredSpeed = 1;
            // Turn off the first floor up call light
            SetCallLight(1, true, false);
        }


        // Compute new motor power here
        errorTotal -= errors[errorLoc];
        errors[errorLoc] = desiredSpeed - GetVelocity();
        errorTotal += errors[errorLoc];
        errorLoc = (errorLoc + 1) % 200;
        power = 0.5 * (desiredSpeed - GetVelocity()) + 0.5 * 0.001 * errorTotal;
        SetMotorPower(power);

    }

    /*
     * This call shuts down the elevator system
     */
    printf("Elevator Shutdown\n");
    ElevatorShutdown();
    return 0;
}



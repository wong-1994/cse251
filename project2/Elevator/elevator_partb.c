#include <stdio.h>
#include <stdlib.h>

#include "ElevatorLib.h"

#define N 200
#define FloorSpeed 3.28
#define FloorTolerance 0.16

#define GoingUp 1
#define GoingDown 2
#define Idle 3
#define DoorOpening 4
#define DoorOpen 5
#define DoorClosing 6
#define DoorClosed 7

int state = Idle;
int desiredSpeed = 0;
bool goingUp = true;

void StateIdle();
void StateGoingUp();
void StateGoingDown();
void StateDoorOpen();
void StateDoorOpening();
void StateDoorClosing();
void StateDoorClosed();
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

    double power;
    double errors[N] = {0};
    double errorTotal = 0;
    int errorLoc = 0;

    /*
     * This loop runs until we shut the elevator system down
     * by closing the window it runs in.
     */
    while (IsElevatorRunning())
    {
        switch (state)
        {
        case Idle:
            StateIdle();
            break;
        case GoingUp:
            StateGoingUp();
            break;
        case GoingDown:
            StateGoingDown();
            break;
        case DoorOpen:
            StateDoorOpen();
            break;
        case DoorOpening:
            StateDoorOpening();
            break;
        case DoorClosing:
            StateDoorClosing();
            break;
        case DoorClosed:
            StateDoorClosed();
            break;
        }

        if (GetCallLight(1, true))
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

void StateIdle()
{
    if (WhatFloorToGoTo(true) != -1)
    {
        if (GetFloor() < WhatFloorToGoTo(goingUp))
        {
            goingUp = true;
            state = GoingUp;
            SetBrake(false);
        }
        else if (GetFloor() > WhatFloorToGoTo(goingUp))
        {
            goingUp = false;
            state = GoingDown;
            SetBrake(false);
        }
        else if (GetFloor() == WhatFloorToGoTo(goingUp))
        {
            state = DoorOpening;
        }
    }
}

void StateGoingUp()
{
    if (GetPosition() > (WhatFloorToGoTo(goingUp) - 1.5) * FloorSpacing)
    {
        desiredSpeed = ((WhatFloorToGoTo(goingUp) - 1) * FloorSpacing - GetPosition()) / (FloorSpacing / 2);
    }
    else
        desiredSpeed = 1;

    if (GetPosition() > (WhatFloorToGoTo(goingUp) - 1) * FloorSpacing - FloorTolerance && GetVelocity() < 0.33)
    {
        // We are arrived!
        desiredSpeed = 0;
        SetMotorPower(0);
        SetBrake(true);
        state = DoorOpening;
    }
}

void StateGoingDown()
{
    if (GetPosition() < (WhatFloorToGoTo(goingUp) + 0.5) * FloorSpacing)
    {
        desiredSpeed = ((WhatFloorToGoTo(goingUp) - 1) * FloorSpacing - GetPosition()) / (FloorSpacing / 2);
    }
    else
        desiredSpeed = 1;

    if (GetPosition() < (WhatFloorToGoTo(goingUp) - 1) * FloorSpacing + FloorTolerance && GetVelocity() < 0.33)
    {
        // We are arrived!
        desiredSpeed = 0;
        SetMotorPower(0);
        SetBrake(true);
        state = DoorOpening;
    }
}

void StateDoorOpening()
{
    if (IsDoorClosed(GetFloor()))
    {
        SetDoor(GetFloor(), true);
    }
    else if (IsDoorOpen(GetFloor()))
    {
        ResetTimer();
        state = DoorOpen;
    }
}

void StateDoorOpen()
{
    if (GetTimer() > 3)
    {
        SetDoor(GetFloor(), false);
        ChangeLoading();
        state = DoorClosing;
    }
}

void StateDoorClosing()
{
    if (IsDoorClosed(GetFloor()))
        state = DoorClosed;
}

void StateDoorClosed()
{
    if (WhatFloorToGoTo(goingUp) == -1)
    {
        SetBrake(true);
        state = Idle;
    }
    else if (WhatFloorToGoTo(goingUp) > GetFloor())
    {
        goingUp = true;
        state = GoingUp;
    }
    else if (WhatFloorToGoTo(goingUp) < GetFloor())
    {
        goingUp = false;
        state = GoingDown;
    }
    else if (WhatFloorToGoTo(goingUp) == GetFloor())
        state = DoorOpening;
}
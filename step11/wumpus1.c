#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Name :  <insert name here>
 *
 * Simple Wumpus game in 1D
 */

/* Add any #defines here */
// Id's for things in our cave
#define Empty 0
#define Wumpus 1
#define End 2
// Number of rooms in our cave
#define CaveSize 20
#define ArraySize (CaveSize + 2)
// Direction I can face
#define Left 0
#define Right 1

/* Add any function prototypes here */
void CreateWorld(int cave[]);
int *GetEmptyRoom(int cave[]);
void DisplayWorld(int cave[], int *agent, int agentDir);
int DifferenceByDirection(int dir);
bool DisplayStatus(int cave[], int *agent);

int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    char command[20];
    int direction;
    int i;

    /* Seed the random number generator */
    srand(time(NULL));

    CreateWorld(cave);
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;

    while (true)
    {
        if (DisplayStatus(cave, agentRoom))
            break;

        DisplayWorld(cave, agentRoom, agentDirection);

        // Get the command
        printf("Command: ");
        scanf("%20s", command);

        if (strcmp(command, "quit") == 0)
        {
            // Exit, we are doing
            break;
        }
        else if (strcmp(command, "move") == 0)
        {
            // Move command
            // What way do we need to go?
            direction = DifferenceByDirection(agentDirection);
            if (*(agentRoom + direction) != End)
                agentRoom += direction;
        }
        else if (strcmp(command, "turn") == 0)
        {
            agentDirection = !agentDirection;
        }
        else if (strcmp(command, "fire") == 0)
        {
            for (i = 1; i < 4; i++)
            {
                direction = DifferenceByDirection(agentDirection);
                if (*(agentRoom + i * direction) == End)
                    break;
                else if (*(agentRoom + i * direction) == Wumpus)
                    *(agentRoom + i * direction) = Empty;
            }
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
}

void CreateWorld(int cave[])
{
    int i = 0;
    int *room;

    // Initialize cave to be empty
    for (i = 0; i < ArraySize; i++)
    {
        cave[i] = Empty;
    }

    // Set the ends
    cave[0] = End;
    cave[ArraySize - 1] = End;

    // Get a random empty room and put the Wumpus in it
    room = GetEmptyRoom(cave);
    *room = Wumpus;
}

int *GetEmptyRoom(int cave[])
{
    int room;

    do
    {
        room = rand() % ArraySize;
    } while (cave[room] != Empty);

    return &cave[room];
}

void DisplayWorld(int cave[], int *agent, int agentDir)
{
    int *room;

    for (room = cave + 1; *room != End; room++)
    {
        if (room == agent)
        {
            switch (agentDir)
            {
            case Left:
                printf("<A ");
                break;
            case Right:
                printf("A> ");
            }

            continue;
        }

        switch (*room)
        {
        // case Wumpus:
        // printf("-W-");
        // break;
        default:
            printf(". ");
            break;
        }
    }

    printf("\n");
}

int DifferenceByDirection(int dir)
{
    if (dir == Left)
        return -1;
    else
        return 1;
}

bool DisplayStatus(int cave[], int *agent)
{
    bool wumpus_dead = true;
    int *room = cave;

    if (*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    if (*(agent - 1) == Wumpus || *(agent + 1) == Wumpus)
    {
        printf("I smell a Wumpus\n");
    }
    for (room = cave + 1; *room != End; room++)
    {
        if (*room == Wumpus)
        {
            wumpus_dead = false;
            break;
        }
    }
    if (wumpus_dead)
    {
        printf("The Wumpus is dead! You Won!!!\n");
        return true;
    }
    // We will retrun true to indicate we are dead!
    return false;
}


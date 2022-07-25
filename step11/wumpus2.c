#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Name :  <insert name here>
 *
 * Simple Wumpus game in 2D
 */

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3

/* Number of rooms in our Cave in each dimension */
#define CaveSize 10
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Up 1
#define Right 2
#define Down 3

void CreateWorld(int cave[ArraySize][ArraySize]);
int *GetEmptyRoom(int cave[ArraySize][ArraySize]);
void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir);
int DifferenceByDirection(int dir);
bool DisplayStatus(int cave[ArraySize][ArraySize], int *agent);

int main()
{
    int *agentRoom;
    int agentDirection;
    char command[20];
    int cave[ArraySize][ArraySize];
    int d;

    /* Seed the random number generator */
    srand(time(NULL));

    CreateWorld(cave);
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 4;

    /* The game loop */
    while (true)
    {
        if(DisplayStatus(cave, agentRoom))
            break;
        DisplayWorld(cave, agentRoom, agentDirection);
        /* Get the command */
        printf("Command: ");
        scanf("%20s", command);
        if (strcmp(command, "quit") == 0)
        {
            /* Exit, we are doing */
            break;
        }
        else if (strcmp(command, "move") == 0)
        {
            d = DifferenceByDirection(agentDirection);
            if (*(agentRoom + d) != End)
                agentRoom += d;
        }
        else if (strcmp(command, "turn") == 0)
        {
            agentDirection++;
            if (agentDirection > Down)
                agentDirection = Left;
        }
        else if (strcmp(command, "fire") == 0)
        {
            int i = 1;

            for(i=1;i<4;i++)
            {
                d = DifferenceByDirection(agentDirection);
                if(*(agentRoom + i * d)==End)
                {
                    break;
                }
                else if(*(agentRoom + i * d) == Wumpus)
                {   
                    *(agentRoom + i * d) = Empty;
                    break;
                }
            }
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
}

void CreateWorld(int cave[ArraySize][ArraySize])
{
    int i, j;
    int *room;
    int c;

    for (i = 0; i < ArraySize; i++)
    {
        for (j = 0; j < ArraySize; j++)
        {
            if (i == 0 || j == 0 || i == ArraySize - 1 || j == ArraySize - 1)
            {
                cave[i][j] = End;
            }
            else
            {
                cave[i][j] = Empty;
            }
        }
    }
    room = GetEmptyRoom(cave);
    *room = Wumpus;
    for(c = 0; c < 10; c++)
    {
        room = GetEmptyRoom(cave);
        *room = Pit;
    }
}

int *GetEmptyRoom(int cave[ArraySize][ArraySize])
{
    int row, col;
    int *room;

    do
    {
        row = rand() % ArraySize;
        col = rand() % ArraySize;

        room = &cave[row][col];
    } while (*room != Empty);

    return room;
}

void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir)
{
    int row, col;
    int *room;

    /* Loop over the rows of the cave */
    for (row = 1; row <= CaveSize + 1; row++)
    {
        /*
         * This loop lets us print an up direction
         * above the agent or a v below the agent
         */

        for (col = 1; col <= CaveSize; col++)
        {
            if (&cave[row][col] == agent && agentDir == Up)
            {
                printf(" ^  ");
            }
            else if (&cave[row - 1][col] == agent && agentDir == Down)
            {
                printf(" v  ");
            }
            else
            {
                printf("    ");
            }
        }

        printf("\n");
        if (row > CaveSize)
            break;

        /*
         * This loop prints the agent or the room contents
         */

        for (col = 1; col <= CaveSize; col++)
        {
            room = &cave[row][col];
            if (room == agent)
            {
                switch (agentDir)
                {
                case Left:
                    printf("<A  ");
                    break;

                case Right:
                    printf(" A> ");
                    break;

                default:
                    printf(" A  ");
                    break;
                }
                continue;
            }

            switch (*room)
            {
            case Wumpus:
                printf("-W- ");
                break;

            case Pit:
                printf("~O~ ");
                break;

            default:
                printf(" .  ");
                break;
            }
        }

        printf("\n");
    }
}

int DifferenceByDirection(int dir)
{
    switch (dir)
    {
    case Up:
        return -ArraySize;

    case Down:
        return ArraySize;

    case Left:
        return -1;

    case Right:
        return 1;
    }
}

bool DisplayStatus(int cave[ArraySize][ArraySize], int *agent)
{
    bool wumpus_dead = true;
    int row, col;

    if (*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    if(*agent == Pit)
    {
        printf("You fell into a pit\n");
        return true;
    }
    if (*(agent - 1) == Wumpus || *(agent + 1) == Wumpus || *(agent - ArraySize) == Wumpus || *(agent + ArraySize) == Wumpus)
    {
        printf("I smell a Wumpus\n");
    }
    if (*(agent - 1) == Pit || *(agent + 1) == Pit || *(agent - ArraySize) == Pit || *(agent + ArraySize) == Pit)
    {
        printf("I feel a draft\n");
    }
    for (row = 1; row < ArraySize - 1; row++)
    {
        for (col = 1; col < ArraySize - 1; col++)
        {
            if (cave[row][col] == Wumpus)
            {
                wumpus_dead = false;
                break;
            }
        }
        if (!wumpus_dead)
            break;
    }
    if (wumpus_dead)
    {
        printf("The Wumpus is dead! You Won!!!\n");
        // return true;
    }
    // We will retrun true to indicate we are dead!
    return false;
}
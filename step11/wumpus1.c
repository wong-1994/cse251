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
#define left 0
#define right 1

/* Add any function prototypes here */
void CreateWorld(int cave[]);
int *GetEmptyRoom(int cave[]);
void DisplayRoom(int cave[], int *agent, int agentDir);

 
int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    char command[20];
    
    /* Seed the random number generator */
    srand(time(NULL));

    CreateWorld(cave);    
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;

    while (true)
    {
        DisplayRoom(agentRoom, agentDirection);

        // Get the command
        printf("Command: ");
        scanf("%20s", command);

        if(strcmp(command, "quit") == 0)
        {
            // Exit, we are doing
            break;
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
    for(i = 0; i < ArraySize; i++)
    {
        cave[i] = Empty;
    }

    // Set the ends
    cave[0] = End;
    cave[ArraySize - 1] = End;
    
    //Get a random empty room and put the Wumpus in it
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

    for(room = cave + 1: *room != End; room++)
    {
        
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

/* 
 * Name : <Insert name here>
 * Program to draw playing cards
 */

void PrintCard(int card, int suit);
void PrintResult(int card1, int card2, int suit1, int suit2);

int main()
{
    int suit1, suit2;
    int card1, card2;
    bool same;
     
    /* 
     . This seeds the random number 
     . generator with the current time 
     */
    
    srand(time(NULL));

    /* Create a random card and suit */
    /* This will compute a random number from 0 to 3 */
    suit1 = rand() % 4;
    card1 = rand() % 13 + 2;

    /* This will compute a random number from 1 to 13 */
    do
    {
        suit2 = rand() % 4;
        card2 = rand() % 13 + 2;
        if (suit1 == suit2 && card1 == card2)
            same = true;
    } while (same);
    

    PrintCard(card1, suit1);
    printf("\n");

    PrintCard(card2, suit2);
    printf("\n");

    PrintResult(card1, card2, suit1, suit2);
    printf("\n"); 
    
}

void PrintCard(int card, int suit)
{
switch(card)
{
case 14:
    printf("Ace");
    break;
    
case 11:
    printf("Jack");
    break;
    
case 12:
    printf("Queen");
    break;
    
case 13:
    printf("King");
    break;
    
default:
    printf("%d", card);
    break;
}
    
    printf(" of ");
    
    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;
        
    case 1:
        printf("Diamonds");
        break;
        
    case 2:
        printf("Spades");
        break;
        
    case 3:
        printf("Clubs");
        break;
    }

}

void PrintResult(int card1, int card2, int suit1, int suit2)
{
    // Compare card
    if (card1 < card2)
        printf("Player 2 wins");
    else if (card1 > card2)
        printf("Player 1 wins");
    else if (card1 == card2)
        {
            // Compare suit
            if (suit1 < suit2)
                printf("Player 1 wins");
            else if (suit1 > suit2)
                printf("Player 2 wins");
            else if (suit1 == suit2)
                printf("There is a tie");
        }
}
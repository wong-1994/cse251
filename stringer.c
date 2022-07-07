#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Program to experiment with strings

int StringLength(char str[]);
void PrintLength(char str[]);
void Reverse(char str[]);
int NumberOfSpaces(char str[]);
int NumberOfAppearances(char str[], char ch);

int main()
{
    // char word[] = "chudge";
    // char myWord[80];
    int i;
    int len;
    char mySenternce[80];

//     printf("Enter a sentence: ");
//     fgets(mySenternce, 80, stdin);
//     len = strlen(mySenternce);
//     mySenternce[len-1] = '\0';
//     printf("The entered sentence is %s\n", mySenternce);

//     printf("Enter a word: ");
//     scanf("%79s", myWord);
//     myWord[79] = '\0';
//     PrintLength(word);
//     PrintLength(myWord); 
//     PrintLength(mySenternce);

    // printf("Enter a word: ");
    // scanf("%79s", myWord);
    // getchar();
    // printf("The entered word is %s\n", myWord);

    printf("Enter a sentence: ");
    fgets(mySenternce, 79, stdin);
    len = strlen(mySenternce);
    mySenternce[len - 1] = '\0';
    // mySenternce[79] = '\0';
    printf("The entered sentence is %s\n", mySenternce);

    printf("The number of spaces is: %d\n", NumberOfSpaces(mySenternce));
    printf("The number of i is %d\n", NumberOfAppearances(mySenternce, 'i'));

    Reverse(mySenternce);
    printf("%s\n", mySenternce);
}

void PrintLength(char str[])
{
    printf("The string %s is %ld characters long\n", str, strlen(str));
}

int StringLength(char str[])
{
    int numChars=0;

    while (str[numChars] != '\0')
    {
        numChars++;
    }
    
    return numChars;
}

void Reverse(char str[])
{
    int front = 0;
    int back = strlen(str) - 1;
    char t;

    while (front < back)
    {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}

int NumberOfSpaces(char str[])
{
    int i;
    int numSpaces = 0;

    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i]==' ')
            numSpaces++;
    }

    return numSpaces;
}

int NumberOfAppearances(char str[], char ch)
{
    int i;
    int numChar = 0;
    char chl;

    for(i=0; str[i] != '\0'; i++)
    {
        chl = tolower(str[i]);
        if(chl==ch)
            numChar++;
    }
    
    return numChar;
}
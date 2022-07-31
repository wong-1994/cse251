#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "transistors.h"

void DisplayTransistor(Tran tran)
{
    printf("Number: %s\n", tran.number);
    switch (tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;

    case PNP:
        printf("Type: PNP\n");
        break;
    }

    switch (tran.caseStyle)
    {
    case TO18:
        printf("CaseStyle: TO18\n");
        break;
    case TO92A:
        printf("CaseStyle: TO92A\n");
        break;
    case TO92C:
        printf("CaseStyle: TO92C\n");
        break;
    case TO220:
        printf("CaseStyle: TO220\n");
        break;
    case TO39:
        printf("CaseStyle: TO39\n");
        break;
    }

    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);
}

Tran InputTransistor()
{
    Tran t1;

    InputString(t1.number, sizeof(t1.number));
    t1.type = InputTransistorType("Input transistor type: ");
    t1.caseStyle = InputCaseStyle("Input case style: ");
    t1.pmax = InputPositiveValue("Input pMax: ");
    t1.icmax = InputPositiveValue("Input icMax: ");

    return t1;
}

void InputString(char *str, int max)
{
    char buffer[100];

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max - 1] = '\0';
}

double InputPositiveValue(char *prompt)
{
    char buffer[100];
    double value = 0;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%lf", &value);
    } while (value <= 0);

    return value;
}

int InputTransistorType(char *prompt)
{
    char buffer[100];
    int type;

    do
    {
        printf("%s", prompt);

        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        if (strcmp(buffer, "NPN") == 0)
            type = NPN;
        else if (strcmp(buffer, "PNP") == 0)
            type = PNP;

    } while ((strcmp(buffer, "NPN") != 0) && (strcmp(buffer, "PNP") != 0));

    return type;
}

int InputCaseStyle(char *prompt)
{
    char buffer[100];
    int style;
    bool flg = true;

    do
    {
        printf("%s", prompt);

        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        if (strcmp(buffer, "TO18") == 0)
        {
            style = TO18;
            flg = false;
        }
        else if (strcmp(buffer, "TO92A") == 0)
        {
            style = TO92A;
            flg = false;
        }

        else if (strcmp(buffer, "TO92C") == 0)
        {
            style = TO92C;
            flg = false;
        }

        else if (strcmp(buffer, "TO220") == 0)
        {
            style = TO220;
            flg = false;
        }

        else if (strcmp(buffer, "TO39") == 0)
        {
            style = TO39;
            flg = false;
        }

    } while (flg);

    return style;
}

bool InputAddTran()
{
    char buffer[100];
    bool addtran;
    bool flg = true;

    printf("Would you like to enter another transistor (Y/N)? ");

    do
    {
        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        if ((strcmp(buffer, "Y") == 0) || (strcmp(buffer, "y") == 0))
        {
            flg = false;
            addtran = true;
        }
        else if ((strcmp(buffer, "N") == 0) || (strcmp(buffer, "n") == 0))
        {
            flg = false;
            addtran = false;
        }
    } while (flg);

    return addtran;
}
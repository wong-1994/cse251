#include <stdio.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>

#include "scheduler.h"

int InputOption()
{
    char buffer[100];
    int value = 0;

    do
    {
        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%d", &value);
    } while (!(value >= 0 && value < 4));

    return value;
}

Event InputEvent(Event evt)
{
    struct tm testTM;

    InputString(evt.event, sizeof(evt.event), "What is the event: ");
    evt.date = InputDate("Event date: ");
    testTM = *localtime(&(evt.date));
    printf("%d/%d/%d\n", testTM.tm_mon+1, testTM.tm_mday, (testTM.tm_year+1900));
    evt.start = InputTime("Start time: ", evt.date);
    evt.end = InputTime("End time: ", evt.date);

    return evt;
}

// void DisplayEvent()

void InputString(char *str, int max, char *prompt)
{
    char buffer[100];

    printf("%s", prompt);

    fgets(buffer, sizeof(buffer), stdin);

    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    strncpy(str, buffer, max);
    str[max - 1] = '\0';
}

time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;
    struct tm test2;
    time_t test;

    do
    {
        printf("%s", prompt);

        // Get a line of up to 100 characters
        fgets(buffer, sizeof(buffer), stdin);

        // Remove any \n we might have input
        if (strlen(buffer) > 0)
        {
            buffer[strlen(buffer) - 1] = '\0';
        }

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while (result == NULL);

    // Convert to time_t format
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = 1;

    printf("%d\n", date.tm_mon+1);
    printf("%d\n", date.tm_mday);
    printf("%d\n", date.tm_year+1900);

    test = mktime(&date);
    printf("%ld", test);
    printf("%s", ctime(&test));

    test2 = *localtime(&test);

    printf("%d\n", test2.tm_mon+1);
    printf("%d\n", test2.tm_mday);
    printf("%d\n", test2.tm_year+1900);

    return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    printf("%s", prompt);

    do
    {
        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
        {
            buffer[strlen(buffer) - 1] = '\0';
        }

        result = strptime(buffer, "%I:%M%p", &time);

    } while (result == NULL);

    return mktime(&time);
}
#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct Event
{
  char event[100];
  time_t date;
  time_t start;
  time_t end;
} Event;

typedef struct Schedule
{
  Event *events;
  int numEvents;
} Schedule;
// struct tm
// {
//   int tm_sec;   /* Seconds.	[0-60] (1 leap second) */
//   int tm_min;   /* Minutes.	[0-59] */
//   int tm_hour;  /* Hours.	[0-23] */
//   int tm_mday;  /* Day.		[1-31] */
//   int tm_mon;   /* Month.	[0-11] */
//   int tm_year;  /* Year	- 1900.  */
//   int tm_wday;  /* Day of week.	[0-6] */
//   int tm_yday;  /* Days in year.[0-365]	*/
//   int tm_isdst; /* DST.		[-1/0/1]*/
// };

void DisplayOption();
void DisplayEvent(Event *evt);
void DisplayEvents(Schedule *schedule);
int InputOption();
Event InputEvent(Event evt);
void InputString(char *str, int max, char *prompt);
time_t InputDate(char *prompt);
time_t InputTime(char *prompt, time_t date);

#endif
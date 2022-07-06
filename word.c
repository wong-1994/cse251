#include <stdio.h>

/* 
 * Name : <Insert name>
 * Program to experiment with character arrays
 */

#define MaxWord 20
 
int main ()
{
    char c;
    char str[MaxWord+1];
    char longest_str[MaxWord+1];
    int len = 0;
    double len_avg = 0;
    int len_counter = 0;
    int len_longest = 0;
    int i;
  
    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do 
    {
        c=getchar();
        if(c != ' ' && c != '.' && len < MaxWord)
        {
            str[len] = c;
            len++;
        }
        else if(c == ' ' && len == 0)
            continue;
        else
        {
            str[len] = 0;
            len_counter += 1;
            len_avg += len;

            if(len_longest<len)
            {
                len_longest = len;
                for(i=0;i<=len;i++)
                    longest_str[i] = str[i];
            }

            printf("%s\n", str);
            len = 0;
        }
    } while (c != '.');
    len_avg = len_avg / (double)len_counter;
    printf("The average word length is %.3f\n", len_avg);
    printf("The longest word entered is %s\n", longest_str);
}
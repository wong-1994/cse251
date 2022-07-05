#include <stdio.h>

/* 
 * Name : <Insert name>
 * Program to experiment with hexadecimal
 * and pointers
 */
 
int main()
{
    int a = 0;
    int b = 5;
    int c = 0x2251;
    
    printf("%d: %x\n", a, a);
    printf("%d: %x\n", b, b);
    printf("%d: %x\n", c, c);
    printf("%lx\n", (long int)&a);
}
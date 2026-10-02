#include <stdio.h>
 #define IN 1 /* True */
 #define OUT 0 /* False */
 /* Write a program that prints its input one word per line.  */
int  main()
{
 int c, state;
 state = OUT;
 while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
        if(state == IN){
            putchar('\n');
        }
        state = OUT;
    } else {
        state = IN;
        putchar(c);
    }
 }
}
#include <stdio.h>
#define IN 1  /* True */
#define OUT 0 /* False */
#define MAX_CHARACTER_LENGTH 127
/* Write a program that */
int main()
{

    int c;
    int wordCounts[MAX_CHARACTER_LENGTH];
    for (int i = 0; i < MAX_CHARACTER_LENGTH; ++i)
        wordCounts[i] = 0;

    while ((c = getchar()) != EOF)
    {
        ++wordCounts[c];
    }
    int count;
    for (int i = 0; i < MAX_CHARACTER_LENGTH; ++i)
    {
        count = wordCounts[i];
        for (int m = 0; m < count; ++m)
        {
            putchar('x');
        }
        if (count > 0)
        {
            putchar('\n');
        }
    }
}
#include <stdio.h>
#define IN 1  /* True */
#define OUT 0 /* False */
#define MAX_WORD_LENGTH 10
/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
int main()
{

    int c, state, wordLength;
    int wordCounts[MAX_WORD_LENGTH + 1];
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i)
        wordCounts[i] = 0;
    state = OUT;
    wordLength = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                ++wordCounts[wordLength];
            }
            wordLength = 0;
            state = OUT;
        }
        else
        {
            state = IN;
            ++wordLength;
        }
    }

    int count;
    putchar('\n');
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i)
    {
        count = wordCounts[i];
        for (int m = 0; m < count; ++m)
        {
            putchar('x');
        }
        if (count > 0)
            putchar('\n');
    }

    int maxFrequency = 0;
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i)
    {
        if (wordCounts[i] > maxFrequency)
        {
            maxFrequency = wordCounts[i];
        }
    }

    for (int row = maxFrequency; row >= 1; --row)
    {
        for (int i = 0; i <= MAX_WORD_LENGTH; i++)
        {
            if (wordCounts[i] >= row)
                putchar('x');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
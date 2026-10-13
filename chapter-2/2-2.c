/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/
#include <stdio.h>
#define MAX 20

int allTrue(int x, int y, int z);

int main()
{
    int c;
    int lim = MAX;
    char s[MAX];
    int allTrue = 1;

    for (int i = 0; allTrue; ++i)
    {
        if (i >= lim - 1)
        {
            allTrue = 0;
        }
        else if ((c = getchar()) == '\n')
        {
            allTrue = 0;
        }
        else if (c == EOF)
        {
            allTrue = 0;
        }else{
            s[i] = c;
        }
    }
}


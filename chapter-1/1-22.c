/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/
/*
Examples:

n= 4
Input: 'a', '', ' b', 'c', 'd'
Output:
'a',
'b', 'c', 'd'

n= 5
Input: 'a', 'b', ' ', ' ', ' ', 'c'
Output:
'a', 'b'
'c',

n= 5
Input: 'a', 'b', ' ', 'c', 'd', 'e', 'f'
Output:
'a', 'b'
'c', 'd', 'e', f

n= 3
Input: 'a', '', ' b', 'c', ' ', ' d', 'e', 'f', 'g', '\n'
Output:
'a',
'b', 'c',
'd', 'e', 'f',
'g'

n= 3
Input:
'a', '', ' b', '\n'
' '  ' '  ' '

Output:
'a',
'b', 'c',
'd', 'e', 'f',
'g'

Solution:
1. Track curr column, c, indexOfLastBlank
2. Get in input and and store each input value in an array of size n +1
3. WHen you reach the last character at the end of the array
is if the last character is a space or new line print the entire array,
m and reset the column and indexOfLastBlank, with the last charater set to '\n'
4. If the last character is not a space print up to index of the last blank
then shift the remaining elements in the array to the front of the array, update the
column count and resetindexOfLastBlank.

*/
#include <stdio.h>
#define N 3

void printArray(char arr[], int len);
void shiftToBeginning(char arr[], int from);

int main()
{
    int c, column, indexOfLastBlank;
    char segment[N + 1];
    column = 0;
    indexOfLastBlank = -1;

    while ((c = getchar()) != EOF)
    {
        if (c != '\n')
        {
            segment[column] = c;
            if (c == ' ')
            {
                indexOfLastBlank = column;
            }
            ++column;
        }
        if (column == N + 1)
        {
            if (c == ' ' || c == '\n')
            {
                printArray(segment, column - 1);
                putchar('\n');
                column = 0;
                indexOfLastBlank = -1;
            }
            else
            {
                if (indexOfLastBlank != -1)
                {
                    printArray(segment, indexOfLastBlank);
                    putchar('\n');
                    shiftToBeginning(segment, indexOfLastBlank + 1);
                    column = column - indexOfLastBlank - 1;
                    indexOfLastBlank = -1;
                }
                else
                {
                    printArray(segment, column - 1);
                    putchar('\n');
                    shiftToBeginning(segment, column - 1);
                    column = 1;
                }
            }
        }
        else if (c == '\n')
        {
            printArray(segment, column);
            putchar('\n');
            column = 0;
            indexOfLastBlank = -1;
        }
    }
    if (column > 0)
{
    printArray(segment, column);
    putchar('\n');
}
}

void printArray(char arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        putchar(arr[i]);
    }
}

void shiftToBeginning(char arr[], int from)
{
    int j = 0;
    for (int i = from; i < N + 1; i++)
    {
        arr[j] = arr[i];
        ++j;
    }
}
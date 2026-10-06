// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?
// n should be a symbolic parameter since it is fixed
// Set n to a fixed value.
/// keep track of current column
/// if current word is nout a tab print it,
// if current word in not a tab and is a new line print it and set column to 0
/// if current word is a tab print spaces for tab stop - column
// when you get to column = tab stop reset colum to 0

#include <stdio.h>
#define N 3 /* Tab stops ever n columns */

/* print the longest input line */
int main()
{
    int column, c, num_spaces_to_print; /* current line length */
    column = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != '\t')
        {
            putchar(c);
            ++column;
            if (c == '\n')
            {
                column = 0;
            }
        }
        else
        {
            num_spaces_to_print = N - column;
            for (int i = 0; i < num_spaces_to_print; ++i)
            {
                putchar(' ');
                ++column;
            }
        }
        if (column == N)
        {
            column = 0;
        }
    }

    return 0;
}

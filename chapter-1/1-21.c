// Write a program entab that replaces strings of blanks by the minimum
// number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
// When either a tab or a single blank would suffice to reach a tab stop, which should be given
// preference?
/**
 *Steps.
 * Run app and of column count within tab stops
 * In crement consecutive spaces seen by each time you usee a space
 * if at a tab stop and consecutive speen is greate than 1 print tab else print space
 * If at a tab stop reset column count and and consectuivte spaces seen
 * IF current char is not a spcae and cosesectuvie spaeen > 0 print space for all consectuvie spaces before prunting current char
 *
 */
// Example n=8 " ", " ", "a" " ", " ", " ", "b", "c"
// Output       " ", " ", "b" " ", " ", " ", "b", c
// Output

// Example n=3 "b ", "", ""
// Output  "b", "/t",

// Example n=3 " ", "", "b"
// Output  " ", " ", "b"

#include <stdio.h>
#define N 3

int main()
{
    int c, column, consec_spaces_seen;
    column = 0;
    consec_spaces_seen = 0;

    while ((c = getchar()) != EOF)
    {
        ++column;
        if (c == ' ')
        {
            ++consec_spaces_seen;
        }
        else
        {
            if (consec_spaces_seen > 0)
            {
                for (int i = 0; i < consec_spaces_seen; ++i)
                {
                    putchar(' ');
                }
                consec_spaces_seen = 0;
            }
            putchar(c);
        }

        if (c == '\n')
        {
            column = 0;
            consec_spaces_seen = 0;
        }
        else if (column == N)
        {
            if (consec_spaces_seen > 0)
            {
                if (consec_spaces_seen > 1)
                {
                    putchar('\t');
                }
                else
                {
                    putchar(' ');
                }
            }

            column = 0;
            consec_spaces_seen = 0;
        }
    }
}

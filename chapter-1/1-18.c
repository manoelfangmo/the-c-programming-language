// “ Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.”
//  Steps
//  Loop backword from len and replace each ang and tab with a \n
//  if first chratacter in /n don't print else print it
// Test case 1:
//  ' ', '\t' '\n'
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define HAS_TRIMMED_NOT_TRIMMED 0
#define HAS_TRIMMED 1
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
int main()
{
    int len, trimmed, start; /* current line length */
    char line[MAXLINE];      /* current input line */
    trimmed = HAS_TRIMMED_NOT_TRIMMED;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (line[len - 1] == '\n')
        {
            start = len - 2;
        }
        else
        {
            start = len - 1;
        }

        for (int i = start; i >= 0 && (trimmed != HAS_TRIMMED); --i)
        {
            if (line[i] != ' ' && line[i] != '\t')
            {
                line[i + 1] = '\n';
                line[i + 2] = '\0';
                trimmed = HAS_TRIMMED;
            }
        }
        if (trimmed == HAS_TRIMMED)
        {
            printf("%s", line);
        }
        trimmed = HAS_TRIMMED_NOT_TRIMMED;
    }

    return 0;
}
/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
//  Steps
//  Write Function that reverses s:
//  copy s into another array
//  start revision only len > 2
//  set the index to begin reversion to len -2 if s ends with a new line character or just  len -1 if it s does not end with a new line character
//  use the copy of s to to change s;
//  Part 2: Coppy each line, reverse and print oupit
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], char copy[], int len);

int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    char copy_to[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        copy(copy_to, line);
        reverse(line, copy_to, len);
        printf("%s", line);
    }
    return 0;
}

// Case 1  s = abc'\n''\0'  len=4
//             0 1 2 3 4
//  begin idx = 2
//  i = 2 , currDx =0
//  s = [c, b, a]
void reverse(char s[], char copy[], int len)
{
    if (len < 2)
    {
        return;
    }
    int beginIdx, currIdx;
    if (s[len - 1] == '\n')
    {
        beginIdx = len - 2;
    }
    else
    {
        beginIdx = len - 1;
    }

    currIdx = 0;
    for (int i = beginIdx; i >= 0; --i)
    {
        s[currIdx] = copy[i];
        ++currIdx;
    }
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
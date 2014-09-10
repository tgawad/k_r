#include <stdio.h>
#define MAXLINE 1000 

int tgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len; /* current line length */
    int max; /*max length seen so far*/
    char line[MAXLINE]; /*current input line*/
    char longest[MAXLINE]; /*longest saved line*/

    max = 0;
    while ((len = tgetline(line, MAXLINE)) > 1)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /*there was a line*/
        printf("LONGEST: %s", longest);
    return 0;
}

/*tgetline: read a line into s, return length*/
int tgetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
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
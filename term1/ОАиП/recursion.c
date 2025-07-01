// Подсчитать длину строки 2 способами

#include <stdio.h>
#define MAXLEN 1000
int str_len (char str[])
{
    int k, len=0;
    for(k=0; k<MAXLEN; k++)
    {
        if (str[k] != '\0')
        len++;
        if (str[k] == '\0')
        {
            return (len);
        }
    }
    return len;
}
int lent (char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    else
        return (1 + lent(str+1));
}
int main()
{
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    printf ("%d\n", str_len(str)-1);
    printf ("%d\n", lent(str)-1);
}
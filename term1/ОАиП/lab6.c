//Дана строка символов, состоящая из произвольного текста, слова разделены пробелами. 
//Вывести на экран порядковый номер слова максимальной длины и номер позиции в строке, с которой оно начинается.

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
    int main()
    {
        char str[MAXLEN], n, maxlen=0, len=0, pos, slnum, prob, i;
        fgets(str, MAXLEN, stdin);
        for (n=0; n<strlen(str)-1; n++)
        {
            if (str[n] == '\n')
                break;
            if (str[n] != ' ')
            {
                len++;
                if (len > maxlen)
                {
                    maxlen = len;
                    pos = n-len+2;
                }
            }
            if (str[n] == ' ')
            {
                len = 0;
            }
        }
        for (i=0; i<=pos; i++)
        {
            if (str[i] == ' ')
            {
                prob++;
            }
            slnum=prob+1;
        }


        printf("Длина максимального слова %d\nПозиция, с которой оно начинается %d\nПорядковый номер слова %d\n", maxlen, pos, slnum);
        return 0;
}
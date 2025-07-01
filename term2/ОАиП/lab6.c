//Рассматриваются слова, содержащиеся в символьных файлах f1 и f2. 
//Выяснить, сколько раз каждое из слов файла f2 встречается в файле f1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main()
{
    FILE *f1, *f2;
    int i = 0;
    int g = 0, m = 0, j=0, count=0;
    char *s2=NULL, *s1=NULL, k;
    char *s1h=NULL, *s2h=NULL;
    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    rewind(stdin);
    s2 = (char *) malloc(sizeof(char));
    while (1)
    {
        k = fgetc(f2);
        if (k == EOF)
        {
            break;
        }
        s2[i] = k;
        i++;
        s2 = (char *) realloc(s2, sizeof(char) * (i + 1));
    }
    s2[i] = '\0';
    i = 0;
    rewind(stdin);
    s1 = (char *) malloc(sizeof(char));
    while (1) {
        k = fgetc(f1);
        if (k == EOF)
        {
            break;
        }
        s1[i] = k;
        i++;
        s1 = (char *) realloc(s1, sizeof(char) * (i + 1));
    }
    s1[i] = '\0';
    i = 0;
    s2h = (char *) malloc(sizeof(char));
    s1h = (char *) malloc(sizeof(char));
    do
    {
        while (s2[i] != ' ' && s2[i] != '\0')
        {
            s2h[g] = s2[i];
            g++;
            i++;
            s2h = (char *) realloc(s2h, sizeof(char) * (g + 1));
        }
        s2h[g] = '\0';
        g = 0;
        i++;
        do
        {
            while (s1[j] != ' ' && s1[j] != '\0')
            {
                s1h[m] = s1[j];
                m++;
                j++;
                s1h = (char *) realloc(s1h, sizeof(char) * (m + 1));
            }
            s1h[m] = '\0';
            m=0;
            j++;
            if (strcmp(s2h, s1h) == 0)
            {
                count++;
            }
            free(s1h);
            s1h = (char *) malloc(sizeof(char));
        } while (s1[j] != '\0');
        j=0;
        printf ("Cлово %s встречается %d раз\n", s2h, count);
        count=0;
        free(s2h);
        s2h = (char *) malloc( sizeof(char));
    } while (s2[i] != '\0');
    free(s1);
    free(s2);
    free(s1h);
    free(s2h);
    fclose(f1);
    fclose(f2);
    return 0;
}
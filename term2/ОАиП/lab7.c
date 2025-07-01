//В командной строке задается имя бинарного файла, в котором хранится информация о видеофильмах (название, тип фильма, год выпуска). 
//Программа реализует следующие операции:
//	- добавляет в файл новую информацию;
//	- исключает информацию о заданных фильмах;
//	- выводит список фильмов соответствующего типа.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct movies // фильмы
{
    char name[50];
    int year;
    char type[50];
};
void add();
void print();
void delete();
void see_type();
int main()
{
    FILE *bin;
    //fopen("films.bin", "w");
    char choose;
    while (1)
    {
        puts("     1-добавить фильм");
        puts("     2-просмотреть фильмы");
        puts("     3-удалить фильм");
        puts("     4-просмотреть фильмы по жанрам");
        puts("     0-окончить");
        fflush(stdin);
        choose = getchar();
        if (choose == '1')
            add();
        if (choose == '2')
            print();
        if (choose == '3')
            delete();
        if (choose == '4')
            see_type();
        if (choose == '0')
            return 0;
    }
}
void add ()
{
    struct movies *tmp;
    FILE *f;
    if ((f=fopen("films.bin", "ab"))==NULL)
        return;
    if ((tmp = (struct movies *)malloc(sizeof(struct movies)))==NULL)
    {
        puts("Error");
        fclose(f);
        exit(0);
    }
    fflush(stdin);
    printf ("Введите название фильма: ");
    scanf("%s", tmp->name);
    printf("Введите год ");
    scanf("%d", &(tmp->year));
    printf("Введите жанр ");
    scanf("%s", tmp->type);
    fwrite (tmp, sizeof(struct movies), 1, f);
    fclose (f);
}
void print ()
{
    struct movies tmp;
    FILE *f;
    if ((f=fopen("films.bin", "rb"))==NULL)
        return;
    int k=0;
    printf("Фильм\tГод\tЖанр\n");
    do
    {
        fseek (f, k*sizeof(struct movies), SEEK_SET);
        fread (&tmp, sizeof(struct movies), 1, f);
        k++;
        if (feof(f))
            return;
        printf("%s\t%d\t%s\n", tmp.name, tmp.year, tmp.type);
    } while (!feof(f));
    fclose (f);
}
void delete ()
{
    char film[50];
    struct movies tmp;
    FILE *f;
    FILE *ftmp;
    if ((f=fopen("films.bin", "rb"))==NULL)
        return;
    if ((ftmp = fopen("tmp.bin", "ab"))==NULL)
        return;
    print();
    printf("Введите название фильма для удаления: ");
    scanf("%s", film);
    do
    {
        fread(&tmp, sizeof(struct movies), 1, f);
        if (feof(f))
            break;
        if (strcmp(film, tmp.name) !=0)
            fwrite(&tmp, sizeof(struct movies), 1, ftmp);

    } while (!feof(f));
    fclose (f);
    fclose (ftmp);
    remove("films.bin");
    rename("tmp.bin", "films.bin");
}
void see_type()
{
    FILE *f;
    f = fopen("films.bin", "rb");
    struct movies tmp;
    char tip[50];
    print();
    printf("Введите жанр: ");
    scanf("%s", tip);
    do
    {
        fread (&tmp, sizeof(struct movies), 1, f);
        if (feof(f))
            break;
        if (strcmp(tip, tmp.type) == 0)
            printf("%s\t%d\t%s\n", tmp.name, tmp.year, tmp.type);
    } while (!feof(f));
    fclose(f);
}
// 9. Имеются сведения о студентах: указывается ФИО, домашний адрес, дата рождения. 
//Сформировать массив, в который записать в алфавитном порядке студентов, которым исполнилось n лет. 
//Ввод, поиск, вывод выполнять в раз-ных функциях.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct date
{
    int day, month, year;
};
struct adres
{
    char *gorod, *ulica;
    int dom, flat;
};
struct univ
{
    char *name;
    struct date birthday;
    struct adres adr;
    int god;
};
void vvod (struct univ *st, int n)
{
    for (int i=0; i<n; i++)
    {
        int j=0;
        printf("Введите ФИО: ");
        fflush(stdin);
        st[i].name = (char*)malloc(1);
        while ((st[i].name[j++] =getchar()) != '\n')
            st[i].name = (char*) realloc(st[i].name, j+1);
        st[i].name[j-1] = '\0';
        j=0;
        printf("Введите дату рождения день/месяц/год через пробел: ");
        scanf("%d %d %d", &st[i].birthday.day, &st[i].birthday.month, &st[i].birthday.year);
        while (st[i].birthday.year > 2022)
        {
            printf("Введите год еще раз: ");
            scanf("%d", &st[i].birthday.year);
        }
        while (st[i].birthday.month > 12)
        {
            printf("Введите месяц еще раз: ");
            scanf("%d", &st[i].birthday.month);
        }
        while (st[i].birthday.month == 1 || st[i].birthday.month == 3 || st[i].birthday.month == 5 ||
                st[i].birthday.month == 7 || st[i].birthday.month == 8 || st[i].birthday.month== 10 || st[i].birthday.month == 12
                && st[i].birthday.day > 31)
        {
            printf("Введите день еще раз: ");
            scanf("%d", &st[i].birthday.day);
        }
        while (st[i].birthday.month == 4 || st[i].birthday.month == 6 || st[i].birthday.month== 9 || st[i].birthday.month == 11
                                                                                                      && st[i].birthday.day > 30)
        {
            printf("Введите день еще раз: ");
            scanf("%d", &st[i].birthday.day);
        }
        while (st[i].birthday.month == 2 && st[i].birthday.year%4 == 0 && st[i].birthday.day > 29)
        {
            printf("Введите день еще раз: ");
            scanf("%d", &st[i].birthday.day);
        }
        while (st[i].birthday.month == 2 && st[i].birthday.year%4 != 0 && st[i].birthday.day > 28)
        {
            printf("Введите день еще раз: ");
            scanf("%d", &st[i].birthday.day);
        }
        printf("Введите город проживания: ");
        fflush(stdin);
        st[i].adr.gorod = (char*)malloc(1);
        while ((st[i].adr.gorod[j++] =getchar()) != '\n')
            st[i].adr.gorod = (char*) realloc(st[i].adr.gorod, j+1);
        st[i].adr.gorod[j-1] = '\0';
        j=0;
        printf("Введите улицу: ");
        fflush(stdin);
        st[i].adr.ulica = (char*)malloc(1);
        while ((st[i].adr.ulica[j++] =getchar()) != '\n')
            st[i].adr.ulica = (char*) realloc(st[i].adr.ulica, j+1);
        st[i].adr.ulica[j-1] = '\0';
        printf("Введите дом и квартиру через пробел: ");
        scanf("%d %d", &st[i].adr.dom, &st[i].adr.flat);
        st[i].god = 2022 - st[i].birthday.year;
        printf("\n");
    }
}
void vyvod (struct univ *st, int n)
{
    int year;
    printf("Введите нужный возраст: ");
    scanf("%d", &year);
    printf("\n");
    for (int i=0; i<n; i++)
    {
        if (st[i].god == year)
        {
            printf("%s %d.%d.%d %s %s %d-%d", st[i].name, st[i].birthday.day, st[i].birthday.month,
                   st[i].birthday.year, st[i].adr.gorod, st[i].adr.ulica, st[i].adr.dom, st[i].adr.flat);
            printf("\n");
        }
    }
}
void alphabet (struct univ *st, int n)
{
    struct univ tmp;
    for (int i=n-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (st[j].name[0] > st[j+1].name[0])
            {
                tmp = st[j];
                st[j] = st[j+1];
                st[j+1] = tmp;
            }
        }
    }
}
int main()
{
    setlocale (LC_ALL, "Russian");
    struct univ *st;
    int n;
    printf("Ввeдите количество студентов: ");
    scanf("%d", &n);
    printf("\n");
    st = (struct univ *) malloc(n*sizeof(struct univ));
    vvod (st, n);
    alphabet(st, n);
    vyvod(st, n);
    return 0;
}
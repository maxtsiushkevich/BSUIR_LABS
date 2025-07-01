//1. В головном модуле ввести структуры.
//Элементами структуры является вторая структура (фамилия, имя, отчество студента и номер семестра) и объединение. 
//В объединение, в зависимости от семестра, записаны номера экзаменов и результаты, а список наименований экзаменов хранится отдельно. 
//В зависимости от запроса в командной строке вывести информацию о студентах за определенный семестр.

#include <stdio.h>
#include <stdlib.h>
//const char *exams[] = { "Logic", "MA", "Geom", "History", "Prog", "Lang", "Polit", "Fisics", "DM"};
struct info
{
    char *surname;
    char *name;
    char *otch;
    int sem_num;
} name;
struct main
{
    struct info name;
    union
    {
        struct
        {
            int log;
            int ma;
            int geom;
        } sem1;
        struct
        {
            int hist;
            int prog;
            int lang;
        } sem2;
        struct
        {
            int polit;
            int fiz;
            int dm;
        } sem3;
    } un;
};

int main()
{
    struct main *stud;
    int n;
    int sem;
    printf("Введите количество студентов: ");
    scanf("%d", &n);
    stud = (struct main *) malloc(n * sizeof(struct main));
    for (int i = 0; i < n; i++) {
        printf("\nВведите ФИО через пробел: ");
        fflush(stdin);
        int j = 0;
        stud[i].name.surname = (char *) malloc(1);
        while ((stud[i].name.surname[j++] = getchar()) != '\n')
            stud[i].name.surname = (char *) realloc(stud[i].name.surname, j + 1);
        stud[i].name.surname[j - 1] = '\0';
        fflush(stdin);
        j = 0;
        stud[i].name.name = (char *) malloc(1);
        while ((stud[i].name.name[j++] = getchar()) != '\n')
            stud[i].name.name = (char *) realloc(stud[i].name.name, j + 1);
        stud[i].name.name[j - 1] = '\0';
        j = 0;
        fflush(stdin);
        stud[i].name.otch = (char *) malloc(1);
        while ((stud[i].name.otch[j++] = getchar()) != '\n')
            stud[i].name.otch = (char *) realloc(stud[i].name.otch, j + 1);
        stud[i].name.otch[j - 1] = '\0';
        j = 0;;
        printf("Введите номер семестра: ");
        while (!scanf("%d", &sem) || sem < 1 || sem > 3)
        {
            fflush(stdin);
            printf("Введите еще раз: ");
        }
        stud[i].name.sem_num = sem;
        if (sem == 1)
        {
            printf("Введите оценки за 1 семестр:\n");
            printf("Логика: ");
            scanf("%d", &stud[i].un.sem1.log);
            printf("MA: ");
            scanf("%d", &stud[i].un.sem1.ma);
            printf("Геометрия: ");
            scanf("%d", &stud[i].un.sem1.geom);
        }
        if (sem == 2)
        {
            printf("Введите оценки за 2 семестр:\n");
            printf("История: ");
            scanf("%d", &stud[i].un.sem2.hist);
            printf("ОАиП: ");
            scanf("%d", &stud[i].un.sem2.prog);
            printf("Иностранный: ");
            scanf("%d", &stud[i].un.sem2.lang);
        }
        if (sem == 3)
        {
            printf("Введите оценки за 3 семестр:\n");
            printf("Политология: ");
            scanf("%d", &stud[i].un.sem3.polit);
            printf("Физика: ");
            scanf("%d", &stud[i].un.sem3.fiz);
            printf("ДМ: ");
            scanf("%d", &stud[i].un.sem3.dm);
        }
    }
    printf("\nВведите номер требуемого семестра\n");
    scanf("%d", &sem);
    for (int i = 0; i < n; ++i)
    {
        if (stud[i].name.sem_num == sem)
        {
            printf("\n   Студент: %s %s %s\n", stud[i].name.surname, stud[i].name.name, stud[i].name.otch);
            switch (sem)
            {
                case 1:
                    printf("   Логика: %d\n   МА: %d\n   Геометрия: %d\n", stud[i].un.sem1.log, stud[i].un.sem1.ma,
                           stud[i].un.sem1.geom);
                    break;
                case 2:
                    printf("   История:%d\n   ОАиП: %d\n   Иностранный: %d\n", stud[i].un.sem2.hist,
                           stud[i].un.sem2.prog, stud[i].un.sem2.lang);
                    break;
                case 3:
                    printf("   Политология:%d\n   Физика: %d\n   ДМ: %d\n", stud[i].un.sem3.polit, stud[i].un.sem3.fiz,
                           stud[i].un.sem3.dm);
                default:
                    printf("   Неправильный ввод.\n");

            }
        }
    }
    for(int i=0; i<n; i++)
    free(stud);
}
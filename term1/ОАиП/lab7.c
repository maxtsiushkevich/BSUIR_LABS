// 14. Ведомость абитуриентов, сдавших вступительные экзамены в университет, содержит ФИО абитуриента, оценки. 
// Определить средний балл по университету и вывести список абитуриентов, средний балл которых выше среднего балла по университету. 
// Первыми в списке должны идти студенты, сдавшие все экзамены на 10.

#include <stdio.h>
#include <stdlib.h>
struct univer
{
    char *name;
    int ball1;
    int ball2;
    int ball3;
    double srball;
} ;
int main()
{
    int n;
    printf("Введите количество студентов: ");
    scanf("%d", &n);
    printf("\n");
    struct univer *student;
    student = (struct univer *) malloc(n*sizeof(struct univer));
    if(student ==NULL)
    {
        printf("\nПамять не выделена");
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        int j=0;
        printf("Введите ФИО: ");
        fflush(stdin);
        student[i].name = (char*)malloc(1);
        while ((student[i].name[j++] =getchar()) != '\n')
            student[i].name = (char*) realloc(student[i].name, j+1);
        printf("Введите оценку 1: ");
        scanf("%d", &student[i].ball1);
        while (student[i].ball1 > 10)
        {
            printf("Введите еще раз: ");
            scanf("%d", &student[i].ball1);
        }
        printf("Введите оценку 2: ");
        scanf("%d", &student[i].ball2);
        while (student[i].ball2 > 10)
        {
            printf("Введите еще раз: ");
            scanf("%d", &student[i].ball2);
        }
        printf("Введите оценку 3: ");
        scanf("%d", &student[i].ball3);
        while (student[i].ball3 > 10)
        {
            printf("Введите еще раз: ");
            scanf("%d", &student[i].ball3);
        }
        student[i].srball = (student[i].ball1+student[i].ball2+student[i].ball3)/3.0;
        printf("Средний балл студента: %.2lf\n", student[i].srball);
        printf("\n");
    }
    printf("\n");
    double srballuniv=0.0;
    double sr=0.0;
    for (int m=0; m<n; m++)
        sr += student[m].srball;
    srballuniv = sr / n;
    struct univer tmp;
    for (int i=n-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (student[j].srball < student[j+1].srball)
            {
                tmp = student[j];
                student[j] = student[j+1];
                student[j+1] = tmp;
            }
        }
    }
    printf("Средний балл по университету: %.2lf\n", srballuniv);
    printf("Студенты со средним баллом > среднего по университету:\n");
    for (int d=0; d<n; d++)
    {
        if (student[d].srball > srballuniv)
        {
            printf("%s", student[d].name);
        }
    }
    free (student);
    return 0;
}
//В матрице размером NxM поменять местами строку, содержащую элемент с наибольшим значением, со строкой, содержащей элемент с наименьшим значением.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, m, max, min, mn, mx;
    int *mas = NULL; // указатель на массив
    printf("Введите количество строк N: ");
    scanf("%d", &n);
    printf("Введите количество столбцов M: ");
    scanf("%d", &m);
    mas = (int *) malloc(n * m * sizeof(int));
    printf ("%d ", mas);
    for (i = 0; i < n; i++) // перебирает каждую строку
        {
        for (j = 0; j < m; j++) // перебирает каждый элемент строки
            {
            printf("Введите элемент %dx%d = ", i, j); // ввод элементов
            scanf("%d", (mas + i * m + j));
            }
    }
    min = *(mas);
    printf ("%d", min);
    max = *(mas+i);
    printf ("%d", max);
    printf("\nМатрица %dx%d:\n", n, m); // вывод матрицы
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %d", *(mas + i * m + j));
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) // поиск максимальный элемент массива
    {
        for (j = 0; j < m; j++)
        {
            if (*(mas + i * m + j) >= max)
            {
                max = *(mas + i * m + j);
                mx = i;
            }
        }
    }
    printf("\nМаксимальный элемент: %d\n", max);
    for (i = 0; i < n; i++) // поиск минимального элемента
    {
        for (j = 0; j < m; j++)
        {
            if (*(mas + i * m + j) < min)
            {
                min = *(mas + i * m + j);
                mn = i;
            }
        }
    }
    printf("Минимальный элемент: %d\n", min);
    for (i = 0; i < n; i++) // переставляет строки
    {
        for (j = 0; j < m; j++)
        {
            if (i == mx)
            {
                printf(" %d", *(mas + mn * m + j));
            }
            else
            {
                if (i == mn)
                {
                    printf(" %d", *(mas + mx * m + j));
                }
                else
                    printf(" %d", *(mas + i * m + j));
            }
        }
        printf("\n");
    }
    free(mas);
    return 0;
}
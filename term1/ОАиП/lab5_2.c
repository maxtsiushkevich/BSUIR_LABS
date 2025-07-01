#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, j, n, m, max, min, mn, mx;
    int **mas;
    printf("Введите количество строк N: ");
    scanf("%d", &n);
    printf("Введите количество столбцов M: ");
    scanf("%d", &m);
    mas = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mas[i] = (int *) malloc(m * sizeof(int));

    for (i = 0; i < n; i++) // перебирает каждую строку
    {
        for (j = 0; j < m; j++) // перебирает каждый элемент строки
        {
            printf("Введите элемент матрицы %dx%d = ", i, j); // ввод элементов
            scanf("%d", &mas[i][j]);
        }
    }
    printf("\nМатрица %dx%d:\n", n, m); // вывод матрицы
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d", mas[i][j]);
        }
        printf("\n");
    }
    max = mas[0][0];
    for (i = 0; i < n; i++) // поиск максимальный элемент массива
    {
        for (j = 0; j < m; j++)
        {
            if (mas[i][j] > max)
            {
                max = mas[i][j];
                mx = i;
            }
        }
    }
    printf("\nМаксимальный элемент: %d\n", max);
    min = mas[0][0]; // поиск минимального элемента
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mas[i][j] <= min)
            {
                min = mas[i][j];
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
                printf(" %d", mas[mn][j]);
            }
            else
            {
                if (i == mn)
                {
                    printf(" %d", mas[mx][j]);
                } else
                    printf(" %d", mas[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
    return 0;
}
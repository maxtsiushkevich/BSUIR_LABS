//Задан массив из k символов. Определить количество различных элементов в массиве.

#include <stdio.h>
int main()
{
    int mas[1000], n, i, k, count = 0, iss[1001];
    printf("Введите количество чисел (n) в массиве:\n");
    scanf("%d", &n);
    printf("Введите числа:\n");

    for (int m = 0; m < 1001; m++)
        iss[m] = 0;

    for (i = 0; i < n; i++)

    {
        printf("mas[%d] = ", i);
        scanf("%d", &mas[i]);
    }

    for (k = 0; k<n; k++)
    {

        if(iss[ mas[k] + 500 ] == 0)
        {
            count++;
            iss[ mas[k] + 500 ] = 1;
        }
    }

    printf("количество различных элементов в массиве = %d", count);
    return 0;
}
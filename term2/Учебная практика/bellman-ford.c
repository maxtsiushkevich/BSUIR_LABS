// Алгортм поиска кратчайшего пути (ищет кратчайший путь от выбранной вершины до остальных) 
// То же самое что и Дейкстра, но работает и с отрицательными ребрами

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **graph, *dist, n, point, INF;
    printf ("Введите количество вершин: ");
    scanf ("%d", &n);
    if (n < 1) {
        printf ("Количество вершин должно быть больше 0\n");
        return 0;
    }
    if (!(graph = (int **)malloc(n * sizeof(int *)))) { // выделение памяти под матрицу расстояний
        printf ("Ошибка выделения памяти\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!(graph[i] = (int *) malloc(n * sizeof(int)))) {
            printf("Ошибка выделения памяти\n");
            return 0;
        }
    }
    if (!(dist = (int *)malloc(n * sizeof(int)))) { // выделение памяти под массив расстояний
        printf ("Ошибка выделения памяти\n");
        return 0;
    }
    for (int i = 0; i < n; i++) { // заполнение матрицы расстояний
        for (int j = 0; j < n; j++){
            if (i == j)
                graph[i][j] = 0;
            else {
                printf("Введите вес ребра %d-%d: ", i, j);
                scanf("%d", &graph[i][j]);
            }
        }
    }
    int sum=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += graph[i][j];
        }
    }
    INF = n*sum*3; // подсчет условной бесконечности (должна быть гарантированна больше любого возможного расстояния)
    while (point < 0 || point >= n) {
        printf ("Вершина отсчета должна быть в интервале [0, %d]\n", n - 1);
        scanf ("%d", &point);
    }
    for (int i = 0; i < n; i++) { // точка отсчета = 0, остальные = INF
        if (i == point)
            dist[i] = 0;
        else
            dist[i] = INF;
    }
    for (int i = 0; i<n; i++) { // поиск минимальных расстояний
        for (int j = 0; j<n; j++) {
            if (graph[i][j] != 0)
            {
                if (dist[j] > dist[i]+graph[i][j])
                {
                    dist[j] = dist[i]+graph[i][j];
                }
            }
        }
    }
    for (int i = 0; i<n; i++) { // проверка на наличие отрицательных циклов
        for (int j = 0; j<n; j++) {
            if (graph[i][j] != 0)
            {
                if (dist[j] > dist[i]+graph[i][j])
                {
                    printf ("В графе присутствует отрицательный цикл\n");
                    return 0;
                }
            }
        }
    }
    printf("Вершины\tРасстояние до вершины\n"); // вывод результатов
    for (int i = 0; i<n; i++)
        printf ("%d\t\t\t%d\n", i, dist[i]);
    free (dist); // освобождение памяти
    free (graph);
    return 0;
}
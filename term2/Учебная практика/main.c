// транспортная задача. Алгоритм min cost flow dijkstra
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
int num;
struct graf
{
    int cap;
    int cost;
    int flow;
    int rest_cap;
    bool edge;
    bool residual;
};
void null (struct graf **graph, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graph[i][j].cap = 0;
            graph[i][j].cost = 0;
            graph[i][j].flow = 0;
            graph[i][j].rest_cap = 0;
            graph[i][j].edge = 0;
            graph[i][j].residual = 0;
        }
    }
}
void result (int post, int prod, int cost, struct graf **graph)
{
    int n = post+prod+2;
    printf("\nМинимальная стоимость: %d\n\n", cost);
    printf("Оптимальный план перевозок:\n\n");
    printf("   ");
    for (int i=1; i<prod+1; i++)
        printf("B%d  ", i);
    printf("\n");
    for(int i=1; i<post+1; i++) {
        printf("A%d  ", i);
        for (int j=post+1; j<n-1; j++) {
            printf("%d  ", graph[i][j].flow);
        }
        printf("\n");
    }
}
void residual (struct graf **graph, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            graph[i][j].residual = 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((graph[i][j].edge == 1) && (graph[i][j].flow < graph[i][j].cap)) {
                graph[i][j].rest_cap = graph[i][j].cap - graph[i][j].flow;
                graph[i][j].residual = 1;
            }
        }
    }
}
int *dijkstra (struct graf **graph, int n)
{
    int *flag;
    int tmp, point, i, temp;
    if (!(flag = (int*) malloc(n*sizeof(int)))) // флаги: 0-не посещена, 1-посещена
        exit (33);
    int *dist;
    if (!(dist = (int*) malloc(n*sizeof(int))))
        exit (33);
    for (i=0; i<n; i++) {
        flag[i] = 0;
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    do {
        tmp=INT_MAX;
        point=INT_MAX;
        for (i=0; i<n; i++) {
            if ((dist[i] < tmp) && (flag[i] == 0)) {
                tmp = dist[i];
                point = i;
            }
        }
        if(point != INT_MAX) {
            for(i=0; i<n; i++) {
                if((graph[point][i].cost >= 0) && (graph[point][i].edge == 1) && (graph[point][i].residual == 1)) {
                    temp=tmp+graph[point][i].cost;
                    if (temp<dist[i]) {
                        dist[i]=temp;
                    }
                }
            }
            flag[point]=1;
        }
    } while (point<INT_MAX);
    if (dist[n-1] == INT_MAX)
        return dist;
    int *dst;
    if (!(dst = (int*) malloc(sizeof(int)*n)))
        exit (33);
    int end = n-1;
    dst[0] = end + 1;
    int k = 1;
    int weight = dist[end];
    while (end != 0) {
        for (i = 0; i<n; i++)
            if ((graph[i][end].edge == 1) && (graph[i][end].residual == 1)) {
                temp = weight - graph[i][end].cost;
                if (temp == dist[i]) {
                    weight = temp;
                    end = i;
                    dst[k] = i+1;
                    k++;
                }
            }
    }
    int *template;
    if (!(template = (int*) malloc(sizeof(int)*k)))
        exit (33);
    int j=0;
    num = k;
    for (i=k-1; i>=0; i--) {
        template[j] = dst[i] - 1;
        j++;
    }
    free(dst);
    free(dist);
    free(flag);
    return template;
}
int main()
{
    int n;
    int post, prod;
    int K;
    struct graf **graph;
    printf("Введите количество поставщиков: ");
    scanf("%d", &post);
    printf("Введите количество продавцов: ");
    scanf("%d", &prod);
    printf("\n");
    n = post+prod+2;
    if (!(graph = (struct graf**) malloc(sizeof(struct graf)*n)))
        return 33;
    for (int i = 0; i < n; i++)
        if (!(graph[i] = (struct graf*) malloc(n * sizeof(struct graf))))
            return 33;
    null (graph, n);
    K=0;
    for (int i = 1; i < 1 + post; i++) {
        printf("Введите запас у %d поставщика: ", i);
        scanf("%d", &(graph[0][i].cap));
        while (graph[0][i].cap < 0) {
            printf("Пропускная сопособность должна быть больше 0: ");
            scanf("%d", &(graph[0][i].cap));
        }
        graph[0][i].rest_cap = graph[0][i].cap;
        graph[0][i].cost = 0;
        graph[0][i].edge = 1;
        graph[i][0].cap = 0;
        graph[i][0].cost = 0;
        K += graph[0][i].cap;
    }
    printf("\n");
    int d = 1;
    for (int i = 1; i < 1 + post; i++) {
        for (int j = post + 1; j < n - 1; j++) {
            printf("Введите стоимость доставки за единицу от %d поставщика к %d потребителя: ", i, d);
            d++;
            scanf("%d", &(graph[i][j].cost));
            while (graph[i][j].cost < 0) {
                printf("Cтоимость должна быть больше 0: ");
                scanf("%d", &(graph[i][j].cost));
            }
            graph[i][j].cap = INT_MAX;
            graph[i][j].rest_cap = INT_MAX;
            graph[i][j].edge = 1;
            graph[j][i].cap = 0;
            graph[j][i].cost = -1 * graph[i][j].cost;
        }
        d = 1;
    }
    printf("\n");
    int kk=0;
    for (int i = post + 1; i < n - 1; i++) {
        printf("Введите потребность у %d потребителя: ", d);
        d++;
        scanf("%d", &(graph[i][n - 1].cap));
        while (graph[i][n - 1].cap < 0) {
            printf("Потребность должна быть больше 0: ");
            scanf("%d", &(graph[i][n - 1].cap));
        }
        graph[i][n - 1].rest_cap = graph[i][n - 1].cap;
        graph[i][n-1].cost=0;
        graph[i][n-1].edge=1;
        graph[n-1][i].cost=0;
        graph[n-1][i].cap=0;
        kk+=graph[i][n - 1].cap;
    }
    int flow=0;
    int cost=0;
    int *path=NULL;
    while (flow<K) {
        residual(graph, n);
        path = dijkstra(graph, n);
        if (path[n-1] == INT_MAX)
            break;
        int min_cap = K-flow;
        for(int i=0; i<num; i++) {
            if(i==num-1)
                break;
            if (graph[path[i]][path[i+1]].rest_cap<min_cap)
                min_cap=graph[path[i]][path[i+1]].rest_cap;
        }
        for(int i=0; i<num; i++) {
            if(i==num-1)
                break;
            graph[path[i]][path[i+1]].flow+=min_cap;
            graph[path[i+1]][path[i]].flow-=min_cap;
            cost+=graph[path[i]][path[i+1]].cost*min_cap;
        }
        flow += min_cap;
    }
    result (post, prod, cost, graph);
    free(graph);
    free(path);
    return 0;
}

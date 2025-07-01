//Организовать список (очередь) автостоянок города.
//В очереди указываются общее количество мест, количество свободных мест и список номеров машин на этой автостоянке. 
//Обеспечить функционирование автостоянок: при появлении новой машины она ставится на свободное место, удаление машины со стоянки. 
//Въезд – выезд со стоянки единственный. 
//Предусмотреть возможность создания новой автостоянки. 
//При постановке автомобиля на стоянку запрашивать номер автостоянки, на которую желаем поставить автомобиль.
//При отcутствии мест машина ставится в очередь ожидания свободного места на соответствующей стоянке.

#include <stdio.h>
#include <stdlib.h>

struct parking //парковка
{
    int number; //номер парковки
    int total_places; //всего мест
    int free_places; // свободных мест
    int *car_number; //номер машин
};

struct waiting
{
    int car_num;
    int park_num;
    struct waiting *nx;
};

struct queue
{
    struct parking park;
    struct queue *next;
};

void add_parking (struct queue **, struct queue **, int); // добавление парковок
void add_car (struct queue *, int, struct waiting **, struct waiting **); // добавление машин на парковку
void del_car (struct queue *, int); // удалить машину с парковки
void see_parking(struct queue *); // просмореть все парковки
void see_car (struct queue *, int); // просмореть автомобили на парковке
void see_waiting (struct waiting *, int); // посмотреть очередь ожидания

int main()
{
    struct queue *h, *t; //указатели на голову и хвост очереди
    struct waiting *hd, *tl; //указатели на голову и хвост очереди
    h=t=NULL;
    hd=tl=NULL;
    int k=1; // количество парковок
    while (1)
    {
        puts("     1-создать парковку");
        puts("     2-добавить автомобиль на выбранную парковку");
        puts("     3-удалить автомобиль с выбранной парковки");
        puts("     4-просмотреть всю информацию о всех парковках");
        puts("     5-просмотреть только автомобили на выбранной парковке");
        puts("     6 Просмотреть очередь ожидания на выбранной парковке");
        puts("     0-окончить");
        fflush(stdin);
        //while (getchar() != '0')
        //{
        char choose;
        choose = getchar();
            if (choose == '1')
            {
                add_parking(&h, &t, k);
                k++;
            }
            if (choose== '2')
                add_car(h, k, &hd, &tl);
            if (choose == '3')
                del_car(h, k);
            if (choose == '4')
                see_parking(h);
            if (choose == '5')
                see_car(h, k);
            if (choose == '6')
                see_waiting(hd, k);
            if (choose == '0')
                return 0;
        //}
    }
}

void add_parking (struct queue **h, struct queue **t, int number)
{
    struct queue *p;
    if (!(p = (struct queue *) malloc(sizeof(struct queue))))
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    p->park.number = number;
    puts("Введите количество мест на парковке: ");
    scanf("%d", &(p->park.total_places));
    p->park.free_places = p->park.total_places;
    p->park.car_number = (int*) malloc(p->park.total_places * sizeof(int));
    for (int i = 0; i < p->park.total_places; i++)
    {
        p->park.car_number[i] = 0; // массив номеров
    }
    if (!(*h))
    {
        *h =*t = p;
    }
    else
    {
        (*t)->next = p;
        *t = p;
    }
    puts("Парковка добавлена\n");
    fflush(stdin);
}

void add_car (struct queue *h, int k, struct waiting **hd, struct waiting **tl)
{
    int number;
    if (!h)
    {
        puts("Парковок нет\n");
        return;
    }
    puts("Введите номер желаемой парковки парковки: ");
    scanf("%d", &number);
    if (number>=k)
    {
        puts("Неверный номер парковки\n");
        return;
    }
    do
    {
        if (h->park.number != number)
        {
            h = h->next;
        }
    } while (h->park.number != number);
    if (h->park.free_places == 0)
    {
        puts("Парковка заполнена. Автомобиль будет добавлен в очередь ожидания\n");
        struct waiting *p;
        if (!(p = (struct waiting*) malloc(sizeof(struct waiting))))
        {
            printf("Ошибка выделения памяти\n");
            exit(1);
        }
        puts("Введите номер автомобиля: ");
        scanf("%d", &(p->car_num));
        p->park_num = number;
        if (!*hd)                         // очередь еще не создана
            *tl = *hd = p;                 // устанавливаем оба указателя (голова и хвост)
            // на единственный элемент очереди
        else                             // очередь уже создана
        {
            (*tl)->nx = p;                // добавляем очередной элемент в хвост очереди
            *tl = p;                      // передвигаем указатель на хвост
        }
        return;
    }
    int i=0;
    if (h->park.car_number[i] != 0)
        i++;
    puts("Введите номер машины:");
    scanf("%d", &(h->park.car_number[i]));
    h->park.free_places--;
    return;
}

void del_car (struct queue *h, int k)
{
    if (!h) {
        puts("Парковок нет\n");
        return;
    }
    int number;
    puts("Введите номер желаемой парковки парковки: ");
    scanf("%d", &number);
    if (number>=k)
    {
        puts("Неверный номер парковки\n");
        return;
    }
    do {
        if (h->park.number != number)
        {
            h = h->next;
        }
    } while (h->park.number != number);
    puts("      Доступные для удаления автомобили: ");
    for (int i = 0; i < h->park.total_places; i++)
    {

        if (h->park.car_number[i] != 0) {
            printf("          %d\n", h->park.car_number[i]);
        }
    }
    puts("Введите номер машины:");
    int delete;
    scanf("%d", &delete);
    for (int i = 0; i < h->park.total_places; i++)
    {
        if (h->park.car_number[i] == delete)
        {
            h->park.car_number[i] = 0;
            h->park.free_places++;
        }
    }
}

void see_parking(struct queue *h)
{
    int count=0;
    if(!h)
    {
        puts("Парковок нет\n");
        return;
    }
    do
    {
        printf("    \nПарковка %d\n", h->park.number);
        printf("        Всего мест: %d\n", h->park.total_places);
        printf("        Свободно мест: %d\n", h->park.free_places);
        printf("        Номера автомобилей на парковке:");
        for (int i = 0; i < h->park.total_places; i++)
        {
            if (h->park.car_number[i] != 0)
            {
                printf("\n          %d", h->park.car_number[i]);
            }
            if (h->park.car_number[i] == 0)
            {
                count++;
            }
        }
        if(count == h->park.total_places)
        {
            puts(" парковка пуста\n");
        }
        printf("\n");
        h=h->next;
    } while (h);
    return;
}

void see_car (struct queue *h, int k)
{
    if (!h)
    {
        puts("Парковок нет\n");
        return;
    }
    printf("Введите номер желаемой парковки\n");
    int number;
    scanf("%d", &number);
    if (number>=k)
    {
        puts("Неверный номер парковки\n");
        return;
    }
    do
    {
        if (h->park.number != number)
        {
            h = h->next;
        }
    } while (h->park.number != number);
    for (int i = 0; i < h->park.total_places; i++)
    {
        if (h->park.car_number[i] != 0)
        {
            printf("          %d\n", h->park.car_number[i]);
        }
    }
}

void see_waiting (struct waiting *h, int k)
{
    if (!h)
    {
        puts("Парковок нет\n");
        return;
    }
    printf("Введите номер желаемой парковки\n");
    int number;
    scanf("%d", &number);
    if (number>=k)
    {
        puts("Неверный номер парковки\n");
        return;
    }
    printf ("Очередь ожидания на парковке %d\n", number);
    do
    {
        if (h->park_num == number)
        {
            printf ("          %d\n", h->car_num);
            h = h->nx;
        }
    } while (h->park_num != NULL);
}
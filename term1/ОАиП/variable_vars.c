#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
double sum(int len, ...)
{
    double sum = 0.0;
    int i;
    double *ptr = NULL;
    va_list pt;
    va_start(pt, len);
    ptr = va_arg(pt, double*);
    while (ptr != NULL)
    {
        for (i = 0; i < len; i++)
        {
            printf("%0.3f ", ptr[i]);
            sum += ptr[i];
        }
        printf("\n\n");
        ptr = va_arg(pt, double*);
    }
    va_end(pt);
    return sum;
}
int main()
{
    double a[] = { 0.4, 2.0, 1.75, 4.53 };
    double b[] = { 3.0, 7.5, 4.45, -5.43 };
    double c[] = { -2.67, 2.4, -6.35, 0.0 };
    int razm = sizeof(a) / sizeof(*a);
    printf("sum = %.3lf\n", sum(razm, a, b, c, NULL));
    return 0;
}
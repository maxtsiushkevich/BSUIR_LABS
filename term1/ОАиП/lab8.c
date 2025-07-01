#include <stdio.h>
#include <math.h>
double yx (double x)
{
    return (((x+1)*sinh(sqrt(x))/sqrt(x)-cosh(sqrt(x))))/4.0;
}
double sx (double x, double y, int *k)
{
    double p, s;
    p = 1;
    s = 0;
    double c;
    for ((*k)=1; fabs(fabs(s) - fabs(y)) >= 0.01 ; (*k)++)
    {
        p *= (x / ( 2 * (*k) *( 2 * (*k) +1)));
        s += (p * pow((*k), 2));
    }
    *k--;
    return s;
}
int main() {
    double g;
    int k=0;
    for (g = 0.2; g <= 0.8; g += 0.06)
    {
        printf ("%lf", g);
        printf(" Y(x)=%lf\t", yx(g));
        printf("S(x)=%lf\t", sx(g, yx(g), &k));
        printf("%d\n", k);
    }
}
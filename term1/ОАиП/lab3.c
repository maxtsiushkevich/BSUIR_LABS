#include <stdio.h>
#include <math.h>
int main()
{
    double  h, y, a, b, p, s, i, k, m;
    int n = 120;
    a = 0.2;
    b = 0.8;
    h = (b-a)/10;
    for (k=a; k<=b; k+=h)
    {
        y= (((k+1)*sinh(sqrt(k))/sqrt(k))-cosh(sqrt(k)))/4.0;
        printf (" y=%lf\t", y);
        p = 1;
        s = 0;
        for (i = 1; i <= n; i++)
        {
            p = p * (k/(2*i*(2*i+1))) ;
            s = s + p*pow(i, 2);
        }
        printf ("s=%lf ", s);
        m = fabs (s-y);
        printf ("|s-y|=%lf\n", m);
    }
    return 0;
}
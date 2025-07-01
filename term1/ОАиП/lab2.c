//ln(f(x)), x^3>0
//tg(x^3)+ f(x), x^3<0
//иначе другая функция

#include <iostream.h>
#include <math.h>
#include <stdio.h>
int main()
{
    double x,y,f,a,s;
    int k;
    printf ("Vvedite x ");
    scanf ("%lf",&x);
    printf ("Vvedite y ");
    scanf ("%lf",&y);
    printf ("Viberitef:1-sh(x),2-x^2,3–exp(x)");
    scanf ("%d", &k);
    switch(k)
    {
        case 1: f=sinh(x);
        break;
        case 2: f=pow(x,2);
        break;
        case 3: f=exp(x);
        break;
        default: printf ("Ne vuibrana funkciya ");
        return 1;
    }
    a=fabs(x*y);
    if (a<5)
    {
        printf ("Net rezultata");
        return 1;
    }
    else
    if (a>10) s=fabs(f)+log(y);
    else
    if (a<=10 && a>5) s=exp(f+y);
    else s=sin(x)+tan(y);
    printf ("RESULT = %lf ", s);
    return 0;
}
//При x = 12.3×10−1 ; y = 15.4; z = 0.252×103 ответ s = 82.8256.

#include <stdio.h>
#include <math.h>
int main()
{
    double x,y,z,a,b,c,d,e,s;
    printf ("vvedite x: ");
    scanf ("%lf",&x);
    printf ("vvedite y: ");
    scanf ("%lf",&y);
    printf ("vvedite z: ");
    scanf ("%lf",&z);
    a = pow(y,x+1);
    b=pow(fabs(y-2),1.0/3.0) + 3;
    c = x+y/2;
    d = fabs(x+y)*2;
    e = pow(x+1,-1/sin(z));
    s = a/b+c/d*e;
    printf ("Result s= %lf", s);
    return 0;
}
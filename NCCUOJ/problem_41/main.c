#include <math.h>
#include <stdio.h>

int main(void)
{
    long long a, b, c, d, e, f;
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
    long long delta = a * e - b * d;
    long long deltax = c * e - b * f;
    long long deltay = a * f - c * d;
    if (delta == 0){
        if (deltax == 0 && deltay == 0){
            printf("Infinitely many solutions");
        }
        else{
            printf("No solution");
        }
    }
    else{
        double x = deltax * 1.00 / delta;
        printf("x=%.2lf\n", x);
        double y = deltay * 1.00 / delta;
        printf("y=%.2lf", y);
    }
}
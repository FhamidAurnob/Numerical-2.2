#include<bits/stdc++.h>
using namespace std;
#define error 0.01

double f(double x)
{
    return 2*x*x*x - 3*x*x - 11*x + 6;
}


void bisection(double a, double b, double dx)
{
    double x1 = a;
    double x2 = x1 + dx;

    printf("\n a= %lf \t b= %lf \t dx= %lf", a,b,dx );


    if (f(x1)*f(x2) >= 0)
    {
        if(x2 < b)
        {
            a = x2;
            bisection(a,b,dx);
        }

        else
            return;
    }

    // printf("\n\t itr \t     x1 \t      x2 \t      x0 \t      fx1 \t     fx2 \t     fx0 \n");
    //int itr = 0;
    double x0;

    while (fabs((x2-x1)/x2) >= error)
    {
//        itr++;
        x0 = (x1+x2)/2;
        //
        //printf("\t %d \t %lf \t %lf \t %lf \t %lf \t %lf \t %lf ",itr, x1, x2, x0, f(x1), f(x2), f(x0));

        if (f(x0) == 0.0)
            break;

        else if (f(x0)*f(x1) < 0)
            x2 = x0;
        else
            x1 = x0;

        //f1 = f(x0)
        //printf("\n\n");
    }

    printf("\nRoot: %lf\n",x0);

    if(x2 < b)
    {
        a = x2;
        bisection(a,b,dx);
    }

}

int main()
{
    double a =1, b = 3;
    double dx = 0.5;           //incremental interval

    bisection(a,b,dx);
    return 0;
}

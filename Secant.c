#include<stdio.h>
#include<math.h>

double error= 0.05;
double x1, x2, x3;
int n, poly[10];

double horner(int poly[], int n, double x)
{
    double result = poly[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

void secant()
{
    double f1 = horner(poly, n, x1);
    double f2 = horner(poly, n, x2);

    int itr = 1;
    x3 = (f2*x1 - f1*x2) / (f2-f1);

    //printf("\n\n %lf  %lf  %lf \n\n", f1,f2,x3);

    while((x3-x2)/x3 >= error)
    {
        itr++;

        x1 = x2;
        f1 = f2;
        x2 = x3;

        f2 = horner(poly, n, x3);
        x3 = (f2*x1 - f1*x2) / (f2-f1);
    }

    printf("\n\nRoot: %lf \n\n", x3);
    printf("\niteration: %d. \n", itr);
}

int main()
{
    x1 = 4;
    x2 = 2;
    int i;

    printf("How many terms? ");
    scanf("%d", &n);

    printf("\nEnter the coefficients: ");
    for(i=0; i<n; i++)
        scanf("%d", &poly[i]);

    secant();
    return 0;
}

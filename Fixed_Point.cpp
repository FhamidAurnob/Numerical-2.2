#include<stdio.h>
#include<math.h>

double error= 0.05;
double x1, x0, poly[10];
int n;

double horner(double poly[], int n, double x)
{
    double result = poly[0];

    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

void fixed()
{
    int i, itr=0;
    double c;

    printf("\n\nHow many terms of g(x)? ");
    scanf("%d", &n);

    printf("\nEnter the coefficients: ");
    for(i=0; i<n; i++)
        scanf("%lf", &poly[i]);

    x1 = horner(poly, n, x0);

    printf("\n\n %lf  \n\n", x1);

    while(c=fabs((x1-x0)/x1) >= error)
    {
        x0 = x1;
        x1 = horner(poly, n, x0);
        itr++;
    }

    printf("\nRoot: %lf \n\n", x1);
    printf("\niteration: %d. \n", itr);


}

int main()
{
    //double x0;

    printf("Enter intial guess: ");
    scanf("%lf", &x0);

    fixed();

    return 0;
}

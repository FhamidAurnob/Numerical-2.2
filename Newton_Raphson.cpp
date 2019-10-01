#include<stdio.h>
#include<math.h>

double error= 0.05;
int poly[10], dpoly[10], n1, n2;
double x0, x1;
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]

double horner(int poly[], int n, double x)
{

    double result = poly[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method

    for (int i=1; i<n; i++)

        result = result*x + poly[i];

    return result;
}

void Newton()
{
    int i;
    double fx0, dfx0;

    printf("How many terms of the derivative? ");
    scanf("%d", &n2);

    printf("\nEnter the coefficients of the derived function: ");
    for(i=0; i<n2; i++)
        scanf("%d", &dpoly[i]);

    fx0 = horner(poly, n1, x0);
    dfx0 = horner(dpoly, n2, x0);

    x1 = x0 - (fx0/dfx0);

    printf("\n\n %lf  %lf  %lf   \n\n", fx0, dfx0, x1 );

    while((x1-x0)/x1 >= error)
    {
        x0 = x1;
        fx0 = horner(poly, n1, x0);

        dfx0 = horner(dpoly, n2, x0);
        x1 = x0 - (fx0/dfx0);
    }

    printf("\n\nRoot: %lf \n\n", x0);

}

int main()
{
    // Let us evaluate value for x = 3
    int i;
    x0 = 0;

    printf("How many terms? ");
    scanf("%d", &n1);

    //int poly[n];

    printf("\nEnter the coefficients: ");
    for(i=0; i<n1; i++)
        scanf("%d", &poly[i]);

    Newton();

    //int n = sizeof(poly)/sizeof(poly[0]);
    //printf("Value of polynomial is %d.", horner(poly, n, x));

    return 0;
}

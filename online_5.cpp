#include<bits/stdc++.h>
using namespace std;
#define Max 100
int main()
{
    double x[Max], fx[Max], sum = 0.0, xreq, prodfunc;

    int n;

    printf("How many records : ");
    scanf("%d", &n);

    for(int i = 0 ; i < n; i++)
    {
        printf("\nEnter the year : ");
        scanf("%lf", &x[i]);

        printf("\nEnter the sales in thousands : ");
        scanf("%lf", &fx[i]);

    }

    printf("\nEnter year for finding sales : ");
    scanf("%lf", &xreq);

    for(int i = 0; i<n ; i++)
    {
        prodfunc = 1.0;
        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                prodfunc *= (xreq - x[j]) / (x[i] - x[j]);
            }
        }
        sum += prodfunc * fx[i];
    }
    printf("\nThe Sales at year %lf is %lf\n", xreq, sum);

    printf("The polynomial that enters the data\n ");
    printf("P = a0 + a1x + a2x^2 + a3x^3 + a4x^4 ");
    return 0;
}

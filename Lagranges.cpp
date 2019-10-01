#include<stdio.h>
#define SIZE 40

int main(void)

{
    double x[SIZE],y[SIZE],f[SIZE],sum=0,value;
    int i,j,n;

    printf("Enter number of points:");
    scanf("%d",&n);

    printf("Enter the values of x :\n");

    for(i=0; i<n; i++)
    {
        scanf("%lf",&x[i]);
    }

    printf("Enter the values of y :\n");

    for(i=0; i<n; i++)
    {
        scanf("%lf",&y[i]);
    }

    printf("\nEnter x for which y is to be calculated :\n");
    scanf("%lf",&value);

    for(i=0; i<n; i++)
    {
        f[i] = 1;

        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                f[i] = f[i] * ( ( value - x[j] ) / ( x[i] - x[j]) );
            }
        }
    }

    for(i=0; i<n; i++)
    {
        sum = sum + f[i] * y[i];
    }

    printf("\nThe result = %lf",sum);

    return 0;

}

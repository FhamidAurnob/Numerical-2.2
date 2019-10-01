//gauss elimination pivoting
#include<bits/stdc++.h>

using namespace std;

int main()
{
    float **a,*temp,app,sum,mult,count=0;
    int i,j,k,n,p;
    printf("Enter no of unknowns : ");
    scanf("%d",&n);
    a = (float**)malloc(n*sizeof(float*));
    for(i = 0; i < n; i++)
        a[i] = (float*)malloc(n*sizeof(float));
    temp = (float*)malloc(n*sizeof(float));
    printf("Enter the elements of augmented matrix row-wise\n");
    for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
            scanf("%f",&a[i][j]);
    for(i=0;i<(n);i++)
    {
        app = a[i][i];
        p = i;
        for(k = i+1; k < n; k++)
            if(fabs(app) < fabs(a[k][i]))
            {
                app = a[k][i] ;
                p = k;
            }
        for(j = 0; j <= n; j++)
        {
            temp[j] = a[p][j];
            a[p][j] = a[i][j];
            a[i][j] = temp[j];
        }
        for(j=i+1;j<n;j++)
        {
            mult = a[j][i]/a[i][i];
            for(k=0;k<=n;k++)
                a[j][k] -= mult*a[i][k];
                count++;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        sum = 0;
        for(j=i+1;j<n;j++)
            sum += a[i][j]*temp[j];
            count++;
        temp[i] = (a[i][n]-sum)/a[i][i];
    }
    printf("****The matrix is : ***\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
    printf("-------------The solution is ----------\n");
    for(i=0;i<n;i++)
        printf("X[%d] = %.2f\n",i+1,temp[i]);
    printf("%d",count);
    for(i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(temp);
    return 0;
}

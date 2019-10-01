#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    double r = pow(x,2.0) - x - 2.0;
    return r;
}
double horner(double poly[],int n,double x)
{
    int i;
    double result = poly[0];
    for(i=1; i<n; i++)
        result = result*x + poly[i];
    return result;
}
int main()
{
    double a,b,x1,x2,x0,del_x,f1,f2,f0,e = 0.05,root;
    double poly[] = {1,-1,-2};
    int n = 3;
    cout<<"Enter lower limit: ";
    cin>>a;
    cout<<"Enter higher limit: ";
    cin>>b;
    cout<<"Enter incremental interval: ";
    cin>>del_x;
    x2 = a;
    while(x2 <= b)
    {
        do
        {
            x1 = x2;
            x2 = x1 + del_x;
            f1 = f(x1);
            f2 = f(x2);
            if(f1==0)
            {
                cout<<"\nThe root is : "<<x1;
                root = horner(poly,n,x1);
                cout<<"\nUsing Horner's method f(x)= "<<root;
                if(root==0)
                    cout<<"\nThis root is exact"<<endl;
                else
                    cout<<"\nThis root is not exact"<<endl;
            }
            if(x2 > b)
                return 0;
        }
        while((f1*f2)>0);
        do
        {
            x0=(x1+x2)/2.0;
            f0=f(x0);
            if(f0==0)
            {
                cout<<"\nThe root is : "<<x0;
                root = horner(poly,n,x0);
                cout<<"\nUsing Horner's method f(x)= "<<root;
                if(root==0)
                    cout<<"\nThis root is exact"<<endl;
                else
                    cout<<"\nThis root is not exact"<<endl;
            }
            if(f1*f0<0)
                x2=x0;
            else if(f2*f0<0)
                x1=x0;
            else
                break;
        }
        while(fabs((x2-x1)/x2)>=e);
        cout<<"\nThe root is: "<<x0;
        root = horner(poly,n,x0);
        cout<<"\nUsing Horner's method f(x)= "<<root;
        if(root==0)
            cout<<"\nThis root is exact"<<endl;
        else
            cout<<"\nThis root is not exact"<<endl;
    }
    return 0;
}

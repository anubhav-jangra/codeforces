#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n,x=0,y=0;
    cin >> n;
    int a[n+1],b[n+1];
    a[0]=0;
    b[0]=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i+1];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i+1];
    }
    sort(a,a+n+1);
    sort(b,b+n+1);
    int d=n,p=n;
    while(d+p>0)
    {
        if(d==0)
        {
            p--;
            y+=b[p];
            p--;
        }
        else if(p==0)
        {
            x+=a[d];
            d--;
            d--;
        }
        else if(a[d]>b[p])
        {
            x+=a[d];
            d--;
            if(a[d]>b[p])
            {
                d--;
            }
            else
            {
                y+=b[p];
                p--;
            }
        }
        else
        {
            p--;
            if(a[d]>b[p])
            {
                d--;
            }
            else
            {
                y+=b[p];
                p--;
            }
        }
    }
    cout << x-y;
    return 0;
}

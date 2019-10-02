#include<bits/stdc++.h>
 
using namespace std;
 
struct rectangle
{
    int w;
    int x;
    int y;
    int z;
};
 
int main()
{
    int n;
    cin >> n;
    int a[n],b[n],c[n],e[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> e[i];
    }
    rectangle d[n],p[n],dp[n];
    for(int i=0;i<n-1;i++)
    {
        if(i)
        {
            d[i].w=max(d[i-1].w,a[i]);
            d[i].x=max(d[i-1].x,b[i]);
            d[i].y=min(d[i-1].y,c[i]);
            d[i].z=min(d[i-1].z,e[i]);
        }
        else
        {
            d[i].w=a[i];
            d[i].x=b[i];
            d[i].y=c[i];
            d[i].z=e[i];
        }
    }
    for(int i=n-1;i>0;i--)
    {
        if(i!=n-1)
        {
            p[i].w=max(p[i+1].w,a[i]);
            p[i].x=max(p[i+1].x,b[i]);
            p[i].y=min(p[i+1].y,c[i]);
            p[i].z=min(p[i+1].z,e[i]);
        }
        else
        {
            p[i].w=a[i];
            p[i].x=b[i];
            p[i].y=c[i];
            p[i].z=e[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            dp[i].w=p[1].w;
            dp[i].x=p[1].x;
            dp[i].y=p[1].y;
            dp[i].z=p[1].z;
        }
        else if(i==n-1)
        {
            dp[i].x=d[n-2].x;
            dp[i].y=d[n-2].y;
            dp[i].w=d[n-2].w;
            dp[i].z=d[n-2].z;
        }
        else
        {
            dp[i].w=max(d[i-1].w,p[i+1].w);
            dp[i].x=max(d[i-1].x,p[i+1].x);
            dp[i].y=min(d[i-1].y,p[i+1].y);
            dp[i].z=min(d[i-1].z,p[i+1].z);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i].w<=dp[i].y&&dp[i].x<=dp[i].z)
        {
            cout << dp[i].w << " " << dp[i].x;
            return 0;
        }
    }
    return 0;
}

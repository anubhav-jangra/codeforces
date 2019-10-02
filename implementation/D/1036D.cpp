#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i)
            a[i]+=a[i-1];
    }
    cin >> m;
    long long b[m];
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        if(i)
            b[i]+=b[i-1];
    }
    if(a[n-1]!=b[m-1])
    {
        cout << -1;
        return 0;
    }
    int d=0,p=0,dp=0;
    while((d<n)&&(p<m))
    {
        if(a[d]==b[p])
        {
            dp++;
            d++;
            p++;
        }
        else if(a[d]<b[p])
            d++;
        else
            p++;
    }
    cout << dp;
	return 0;
}

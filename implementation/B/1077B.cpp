#include<bits/stdc++.h>
 
using namespace std;
 
#define sp << " " <<
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,dp=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<n-1;i++)
    {
        if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
        {
            dp++;
            a[i+1]=0;
        }
    }
    cout << dp;
	return 0;
}

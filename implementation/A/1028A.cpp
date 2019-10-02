#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m,d,p;
    cin >> n >> m;
    bool x=0;
    char a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='B'&&x==0)
            {
                d=i;
                p=j;
                x=1;
            }
        }
    }
    int dp=0;
    for(int i=p;i<m;i++)
    {
        if(a[d][i]=='B')
            dp++;
    }
    cout << d+(dp+1)/2 << " " << p+(dp+1)/2;
    return 0;
}

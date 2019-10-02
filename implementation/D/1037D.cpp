#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> g[200001];
 
bool isparent(int d,int p)
{
    for(int i=0;i<g[d].size();i++)
    {
        if(g[d][i]==p)
            return true;
    }
    return false;
}
 
int main()
{
    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dp[n];
    for(int i=0;i<n;i++)
        cin >> dp[i];
    if(dp[0]!=1)
    {
        cout << "No";
        return 0;
    }
    else if(n==1)
    {
        cout << "Yes";
        return 0;
    }
    bool z[n+1]={0};
    int d=0,p=1;
    z[1]=1;
    while(p<n&&d<n)
    {
        if(z[dp[p]]==1)
        {
            cout << "No";
            return 0;
        }
        z[dp[p]]=1;
        if(isparent(dp[p],dp[d]))
        {
            p++;
        }
        else
        {
            d++;
            z[dp[p]]=0;
        }
    }
    if(p==n)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

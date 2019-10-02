#include<bits/stdc++.h>
 
using namespace std;
 
#define sp << " " <<
 
int h[1000001]={0};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp;
    int a[n];
    long long s=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        s+=a[i];
        h[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        s-=a[i];
        h[a[i]]--;
        if(s%2==0&&s/2<=1000000)
        {
            if(h[s/2])
                dp.push_back(i+1);
        }
        h[a[i]]++;
        s+=a[i];
    }
    cout << dp.size() << endl;
    for(int i=0;i<dp.size();i++)
    {
        cout << dp[i] << " ";
    }
	return 0;
}

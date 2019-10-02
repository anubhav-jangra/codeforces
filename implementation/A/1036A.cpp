#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long d,p;
    cin >> d >> p;
    if(p%d==0)
        cout << p/d;
    else
        cout << p/d+1;
	return 0;
}

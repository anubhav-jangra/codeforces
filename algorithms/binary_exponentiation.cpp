#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binexp_r(ll a, ll b)
{
	if(b==0)
		return 1;
	ll res = binexp_r(a, b/2);
	if(b&1)
		res *= res * a;
	else
		res *=res;
	return res;
}

ll binexp(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
			res *= a;
		a = a * a;
		b>>=1;
	}
	return res;
}

int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<binexp_r(a,b);
	return 0;
}
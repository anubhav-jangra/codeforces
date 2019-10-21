#include <bits/stdc++.h>
	
using namespace std;

#define ll long long int
#define pb push_back

#define N 1000000

vector<ll> trial_division1(ll n)
{
	vector<ll> prime_factors;
	ll d = 2;
	for(; d * d <= n; ++d)
	{
		while(n%d == 0)
		{
			prime_factors.push_back(d);
			n /= d;
		}
	}

	if(n > 1)
		prime_factors.push_back(n);
	return prime_factors;
}

//wheel factorization
vector<ll> trial_division2(ll n)
{
	vector<ll> prime_factors;
	
	while(n % 2 == 0)
	{
		prime_factors.push_back(2);
		n /= 2;
	}
	
	for(ll d = 3; d * d <= n; d += 2)
	{
		while(n % d == 0)
		{
			prime_factors.push_back(d);
			n /= d;
		}
	}
	
	if(n > 1)
		prime_factors.push_back(n);

	return prime_factors;
}

vector<ll> trial_division3(ll n)
{
	vector<ll> prime_factors;
	for(int d : {2, 3, 5})
		while(n % d == 0)
		prime_factors.push_back(d), n /= d;

	int i = 0;
	static array<int, 8> increaments = {4, 2, 4, 2, 4, 6, 2, 6}; // can also be just {4, 2} as it also covers all prime numbers
	
	for(ll d  = 5; d * d <= n; d += increaments[i++])			// with some more extra numbers than the array used
	{
		while(n % d == 0)
			prime_factors.push_back(d), n /= d;
		
		if( i == 8)
			i = 0;
	}
	if(n > 1)
		prime_factors.push_back(n);

	return prime_factors;	
}

// using sieve of Eratosthenes

int min_prime[N];
void sieve()
{
	min_prime[0] = 1, min_prime[1] = 1;
	for(ll i = 2; i <= N; ++i)
	{
		if(!min_prime[i])
			for(ll j = i * i; j <= N; j += i)
				if(!min_prime[j])
					min_prime[j] = i;
	}

	for (int i = 0; i < N; ++i)
	{
		if(!min_prime[i])
			min_prime[i] = i;
	}
}

vector<ll> trial_division4(ll n)
{
	vector<ll> prime_factors;
	while(n != 1)
	{
		prime_factors.pb(min_prime[n]);
		n /= min_prime[n];
	}
	return prime_factors;
}

int fermat(int n)
{
	int a = ceil(sqrt(n));
	int b2 = a * a - n;
	int b = round(sqrt(b2));
	while(b * b != b2)
	{
		a = a + 1;
		b2 = a * a - n;
		b = round(sqrt(b2));
	}
	return a - b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	// chrono::steady_clock::time_point begin, end;

	
	// // begin = chrono::steady_clock::now();
	
	// // for(auto e : trial_division1(n))
	// // 	cout << e << " ";
	// // cout << "\n";
	
	// // end = chrono::steady_clock::now();
	// // cout << "Time difference = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() <<endl;

	
	// begin = chrono::steady_clock::now();
	
	for(auto e : trial_division1(n))
		cout << e << " ";
	// cout << "\n";
	
	// end = chrono::steady_clock::now();
	// cout << "Time difference = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() <<endl;

	return 0;
}

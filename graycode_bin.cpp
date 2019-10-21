#include<bits/stdc++.h>
using namespace std;

int gray(int n)
{
	return n ^ (n >> 1);
}

int rev_g(int g)
{
	int n = 0;
	for(;g; g >>= 1)
		n ^= g;
	return n;
}

int main()
{
	int a = 0b111;
	cout << a;

	cout <<"\nGray: "<< gray(a);
	cout <<"\nnumber: "<< rev_g(gray(a));

	return 0;
}
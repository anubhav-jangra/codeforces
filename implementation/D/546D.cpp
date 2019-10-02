#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
const int MAXN = 1000*1000;
unordered_map<int,int> factors[MAXN+10];
vector<bool> isprime(MAXN+10, true);
int primeFactor[MAXN+10];

void init() {
   isprime[0] = isprime[1] = false;
   for(int i = 2; i*i <= MAXN; i++) {
     if(isprime[i]) {
       for(int j = i*i; j <= MAXN; j += i) {
          isprime[j] = false;
          primeFactor[j] = i;
       }
     }
   }
   for(int i = 2; i <= MAXN; i++) {
     if(isprime[i]) factors[i][i] = 1;
     else {
       int dv = primeFactor[i];
       factors[i] = factors[i/dv];
       factors[i][dv]++;
     }
   }
}
*/

long long int factor(long long int n) {
    int count = 0; 
    while(n % 2 == 0) {
        count++;
        n /= 2;
    }
    for(long int i = 3; i <= sqrt(n); i += 2) {
        while(n % i == 0) {
            count++;
            n /= i;
        }
    }
    if(n > 2)
        count++;
    
    return count;
}

int main() {
    long long int t, a, b, count;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        count = 0;
        for(long long int i = b+1; i <= a; i++)
            count += factor(i);
        cout<<count<<endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    long long int n, m;
    short a, b;
    cin>>n>>m>>a>>b;
    if(n%m == 0) {
        cout<<0;
        return 0;
    }
    long long int sum = 0;
    sum = (m - (n%m)) * a;
    if( sum > (n%m) * b)
        sum = n%m * b;
    cout<<sum;
    return 0;
}

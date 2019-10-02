#include <iostream>

using namespace std;

int main()
{
    int i,n,small,large,pos1=0,time;
    cin>>n;
    int pos2=n-1;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    large=a[0];
    small=a[n];
    for(i=0;i<n;i++)
    {
        if(a[i]>large)
        {large=a[i];
        pos1=i;
        }
        if(a[n-1-i]<small)
        {
            small=a[n-1-i];
            pos2=n-1-i;
        }

    }
    time=pos1+(n-1-pos2);
    if(pos1>pos2)
        cout<<time-1;
    else
        cout<<time;
    return 0;
}

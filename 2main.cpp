#include <iostream>

using namespace std;

int main()
{
    int i,j,k,n,diag1=0,diag2=0,flag=1;
    cin>>n;
    int a[n][n],c[n]={0},r[n]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    cout<<"you have entered"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n;i++)
    {  diag1=diag1+a[i][i];
       diag2=diag2+a[i][i];
        for(j=0;j<n;j++)
         r[i]=r[i]+a[i][j];
         for(k=0;k<n;k++)
         {
            c[i]=c[i]+a[k][i];
         }
    }
    for(i=0;i<n-1;i++)
    {


        if((r[0]!=r[i+1])||(c[0]!=c[i+1])||(diag1!=diag2))
      {
        flag=0;break;
      }
      if(flag==0)
        break;
    }
   // cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
    //cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
    //cout<<diag1<<" "<<diag2<<endl;

    if(flag==1)
        cout<<"MAGIC MATRIX";
    else
        cout<<"NOT A MAGIC MATRIX";

    return 0;
}

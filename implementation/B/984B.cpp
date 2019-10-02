#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

int return_val(bool arr[], int i, int j)
{
    int ans = 0;
    
    for(int a = max(i - 1, 0); a <= min(i + 1, n - 1); a++)
    {
        for(int b = max(j - 1, 0); b <= min(j + 1, m - 1); b++)
        {
            if(arr[a * m + b])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int count = 0;
    cin>>n>>m;
    if(count != 0)
        cout<<endl;
    char temp;
    bool arr[n * m] = {};
    char A[n*m] = {};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin>>temp;
            if(temp == ' ' || temp == '\n')
                cin>>temp;
            if(temp == '*')
            {
                arr[i * m + j] = true;
                  A[i * m + j] = '*';
            }
            else
            {
                arr[i * m + j] = false;
                  A[i * m + j] = temp;
            }
            //cout<<"A["<<i * m + j<<"] => "<<A[i*m+j]<<endl;
        }
    bool bo_ol = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!arr[i * m + j])
            {
                int val = return_val(arr, i, j);
                //cout<<"current value is -> "<<val<<endl;
                if(val == 0)
                {
                    if(A[i * m + j] != '.')
                    {
                        cout<<"NO";
                        return 0;
                    }
                    else 
                        continue;
                }
                if(A[i * m + j] - 48 != val)
                {
                    cout<<"NO";
                    return 0;
                }   
            }
        }
    }
    cout<<"YES";
}


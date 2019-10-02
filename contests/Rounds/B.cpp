#include <iostream>
#include <algorithm>
using namespace std;

void printArray(const int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool canEat(const int arr[], int i, int j, int k) {
    if(arr[i] > arr[j] && arr[i] <= arr[j] + k)
        return true;
    return false;
}

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n], vec[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i = 0; i < n; i++)
        vec[i] = arr[i] + k;
    int i = 0, j = 0;
    while(j < n) {
        if(vec[j] - k < arr[i]) {
            if(vec[j] >= arr[i])
                vec[j] = -1;
            j++;
        } else 
            i++;
    }

    int count = 0;
    for(int i = 0; i < n; i++)
        if(vec[i] > 0)
            count++;
    cout<<count;
    return 0;
}

// first attempt
/*
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] == -1)
                continue;
            if(canEat(arr, i, j, k))
                arr[j] = -1;
            else
                break;
        }
    }
 */

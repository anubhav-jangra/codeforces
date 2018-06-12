#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isBalanced(string s) {
    stack<char> vec;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
            vec.push(s[i]);
        else {
            if( !vec.empty() )
                vec.pop();
            else
                return false;
        }
    }
    if(vec.empty())
        return true;
    else
        return false;
}

int main() {
    int n;
    cin>>n;
    vector<string> vec(n), arr;
    string temp;
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
        if(isBalanced(vec[i]))
            a++;
        else if(vec[i].at(0) == ')' && isBalanced(vec[i].substr(1, vec[i].length()) )  ) {
            b++;
        } else if(vec[i].at(vec[i].length() - 1) == '(' && isBalanced(vec[i].substr(0, vec[i].length() - 1) )  ) {
            c++;
        } else {
            arr.push_back(vec[i]);
        }
    }
// first attempt
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size(); j++) {
            if(isBalanced( arr[i] + arr[j] ))
                d++;
        }
    }
    //cout<<"a -> "<<a<<" b -> "<<b<<" c -> "<<c<<" d -> "<<d<<endl;
    cout<<a*a + b*c + d;
    return 0;
}


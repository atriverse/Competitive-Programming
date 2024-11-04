#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int arr[5]={1,5,10,20,100};
    int count=0;

    for(int i=4;i>=0;i--){
        int temp=t/arr[i];
        count+=temp;
        t=t%arr[i];
    }
    cout<<count;
    return 0;
}
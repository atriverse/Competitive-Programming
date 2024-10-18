#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int flag=0;
    while (t--)
    {
        int x;
        cin>>x;
        if(x==1){
            flag=1;
        } 
    }
    if(flag==1){
        cout<<"HARD"<<endl;
    }
    else{
        cout<<"EASY"<<endl;
    }

    return 0;
}
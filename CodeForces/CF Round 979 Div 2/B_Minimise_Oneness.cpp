#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        if (i==0)
        {
            cout<<'1';
        }
        else{
            cout<<'0';
        }
        
    }
    cout<<endl;
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
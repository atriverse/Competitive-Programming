#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,h;
    cin >> n >> h;
    int count=0;
    while (n--)
    {
        int x;
        cin>>x;
        count+=(x>h)?2:1;
    }
    cout<<count;
    return 0;
}
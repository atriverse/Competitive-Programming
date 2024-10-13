#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans=0;
    int mx=0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        ans-=a;
        ans+=b;
        mx=max(mx,ans);
    }
    cout<<mx;
    return 0;
}
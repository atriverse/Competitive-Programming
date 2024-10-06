#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = v[0];
        for (int i = 1; i < n; i++){
            ans=(ans+v[i])/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
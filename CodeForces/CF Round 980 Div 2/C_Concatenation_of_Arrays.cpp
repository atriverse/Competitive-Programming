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
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(2));
        vector<ll> b(2*n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
            b[2 * i] = a[i][0];
            b[2 * i + 1] = a[i][1];
        }
        sort(b.begin(), b.end());
        map<ll, ll> m;
        vector<vector<ll>> c(n, vector<ll>(2));

        ll index = 1;
        for (ll i = 0; i < 2 * n; i++)
        {
            if (m.find(b[i]) == m.end())
            {
                m[b[i]] = index++;
            }
        }

        for(ll i = 0; i < n; i++){
            c[i][0] = m[a[i][0]];
            c[i][1] = m[a[i][1]];
        }

        vector<vector<ll>> res(n, vector<ll>(3));
        for(ll i = 0; i < n; ++i){
            ll sum=c[i][0]+c[i][1];
            res[i][0] = sum;
            res[i][1] = a[i][0];
            res[i][2] = a[i][1];
        }

        sort(res.begin(), res.end(), [&](const vector<ll>& a, const vector<ll>& b) {
            return a[0] < b[0];
        });
        for(ll i = 0; i < n; ++i){
            cout<<res[i][1]<<" "<<res[i][2]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
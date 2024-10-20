#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ll c = 0, p = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (c + (n - i + 1) * (v[i] - v[i - 1]) >= k)
        {
            p += (k - c);
            break;
        }
        else
        {
            p += (n - i + 1) * (v[i] - v[i - 1]) + 1;
            c += (n - i + 1) * (v[i] - v[i - 1]);
        }
    }

    cout << p << '\n';

    ll ans = 0, r = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += v[i] * (n - r);
        c += v[i] * (n - r);

        if (ans >= k)
        {
            c -= (ans - k);
            break;
        }

        ll x = v[i], count = 1;
        for (++i; i < n && v[i] == x; count++, i++)
            ;
        i--;

        ans += (n - count - r);
        r += count;

        if (ans >= k)
        {
            c -= (ans - k);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

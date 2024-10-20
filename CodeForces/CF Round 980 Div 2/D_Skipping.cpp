#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<ll> dp(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        dp[i] = max(a[i] + dp[i + 1], dp[b[i]]);
    }

    cout << dp[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

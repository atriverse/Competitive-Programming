#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<ll> k(q);
    for (int i = 0; i < q; i++) {
        cin >> k[i];
    }
    
    vector<ll> coords;
    for (ll xi : x) {
        coords.push_back(xi);
        coords.push_back(xi + 1);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    int m = coords.size();
    vector<int> diff(m, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int start = lower_bound(coords.begin(), coords.end(), x[i]) - coords.begin();
            int end = lower_bound(coords.begin(), coords.end(), x[j] + 1) - coords.begin();
            diff[start]++;
            diff[end]--;
        }
    }
    
    vector<ll> count(n * (n - 1) / 2 + 1, 0);
    int active = 0;
    for (int i = 0; i < m - 1; i++) {
        active += diff[i];
        count[active] += coords[i + 1] - coords[i];
    }
    
    for (int i = 0; i < q; i++) {
        if (k[i] <= n * (n - 1) / 2) {
            cout << count[k[i]] << " ";
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

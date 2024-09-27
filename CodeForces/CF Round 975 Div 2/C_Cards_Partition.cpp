#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_partition(const vector<ll>& a, ll k, ll size) {
    ll needed = 0;
    for (ll count : a) {
        if (count < size) {
            needed += size - count;
            if (needed > k) return false;
        }
    }
    return true;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll left = 1, right = 2e9;
    ll result = 1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (can_partition(a, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << result << "\n";
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

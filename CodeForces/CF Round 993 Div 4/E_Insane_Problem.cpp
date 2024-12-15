#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(ll k, ll l1, ll r1, ll l2, ll r2) {
    ll ans = 0;
    
    // For each x in [l1, r1]
    for (ll x = l1; x <= r1; x++) {
        // Find lowest power n where k^n * x >= l2
        ll low = 0, high = 60;
        ll first = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll val = 1;
            bool overflow = false;
            
            for (int i = 0; i < mid && !overflow; i++) {
                if (val > r2/k) overflow = true;
                val *= k;
            }
            
            if (!overflow && val <= r2/x && val * x >= l2) {
                first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (first == -1) continue;
        
        // Find highest power n where k^n * x <= r2
        low = first, high = 60;
        ll last = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll val = 1;
            bool overflow = false;
            
            for (int i = 0; i < mid && !overflow; i++) {
                if (val > r2/k) overflow = true;
                val *= k;
            }
            
            if (!overflow && val <= r2/x && val * x <= r2) {
                last = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (last >= first) {
            ans += last - first + 1;
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        cout << solve(k, l1, r1, l2, r2) << "\n";
    }
    
    return 0;
}

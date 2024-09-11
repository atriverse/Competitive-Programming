#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool possible(ll lim, ll a, ll b, ll k){
    ll cnt = lim / b + 1;
    if(lim >= a){
        ll extra = (lim - a) / b + 1;
        cnt += extra;
    }
    return cnt >= k;
}

void solve(){
    ll a, b, k;
    cin >> a >> b >> k;
    // 0 a b b + a - 0, b + a + b - a
    // 0, a, b, b + a, 2b, 2b + a, 3b, 3b + a, 4b
    // 0b, 0b + a, 1b, 1b + a, 2b, 2b + a, 3b, 3b + a, 4b, 4b + a
    ll lo = 0, hi = 1e18;
    ll ans = hi;
    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        if(possible(mid, a, b, k)){
            ans = mid;
            hi = mid - 1;
        }else lo = mid + 1;
    }
    cout << ans << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	return 0;
}

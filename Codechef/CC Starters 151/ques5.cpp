#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m;
    cin >> m >> n;
    vector<ll> ar, br;
    for(ll i=1; i<=n; i++){
        ll el;
        cin >> el;
        if(el == 1){
            ar.push_back(i);
        }else if(el == 2){
            br.push_back(i);
        }else if(el == 3){
            ar.push_back(i);
            br.push_back(i);
        }
    }
    vector<ll> pa, pb;
    pa.push_back(0);
    pb.push_back(0);
    for(auto &it: ar){
        pa.push_back(it + pa.back());
    }
    for(auto &it: br){
        pb.push_back(it + pb.back());
    }
    for(ll i=1; i<=n; i++){
        ll ia = upper_bound(ar.begin(), ar.end(), i) - ar.begin();
        ll as = ia * i - pa[ia];
        ll rem = ar.size() - ia;
        as += pa.back() - pa[ia] - rem * i;
        ll ib = upper_bound(br.begin(), br.end(), i) - br.begin();
        ll bs = ib * i - pb[ib];
        rem = br.size() - ib;
        bs += pb.back() - pb[ib] - rem * i;
        ll ans = abs(as - bs);
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
    return 0;
}

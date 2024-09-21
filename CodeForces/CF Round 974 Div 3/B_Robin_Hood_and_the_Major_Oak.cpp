#include <iostream>

using namespace std;
#define ll long long
bool isEvenLeaves(ll n, ll k) {
    if (n < 1) return true;  // No leaves before year 1
    
    ll start_year =  n - k + 1;
    ll odd_count=(start_year%2==0)?k/2:(((k-1)/2)+1);
    return odd_count % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        cout << (isEvenLeaves(n, k) ? "YES\n" : "NO\n");
    }
    
    return 0;
}

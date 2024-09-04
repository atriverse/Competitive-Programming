/*
Let's duplicate the array a and concatenate it with itself. Now, a should have length 2n and ai=ai−n for all n<i≤2n. Now, the j'th element of the i'th rotation is ai+j−1.

It can be shown for any integer x, it belongs in rotation ⌊x−1n⌋+1 and at position (x−1)modn+1. Let rl denote the rotation for l and rr denote the rotation for r. If rr−rl>1, we are adding rr−rl−1 full arrays to our answer. The leftovers is just the suffix of rotation rl starting at position l and the prefix of rotation of rr starting at position r. This can be done with prefix sums. You may need to handle rl=rr separately.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), ps(1);
        /// Reads the values of the `a` array and calculates the prefix sum `ps`.
        /// The prefix sum `ps` is initialized with 0 and each element `r` of `a` is added to the previous prefix sum value.
        for (ll &r : a) {
            cin >> r;
            ps.push_back(ps.back() + r);
        }
        /// Calculates the prefix sum of the `a` array and stores it in the `ps` vector.
        /// Each element `r` of the `a` array is added to the previous prefix sum value to
        /// build the `ps` vector.
        for (ll &r : a) {
            ps.push_back(ps.back() + r);
        }
        while (q--) {
            ll l, r;
            cin >> l >> r;
            l--; r--;
            ll i = l / n, j = r / n;
            l %= n; r %= n;
            cout << ps[n] * (j - i + 1) - (ps[i + l] - ps[i]) - (ps[j + n] - ps[j + r + 1]) << "\n";
        }
    }
}
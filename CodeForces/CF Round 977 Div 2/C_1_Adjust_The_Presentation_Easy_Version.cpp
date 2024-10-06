#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isGood(const vector<int>& a, const vector<int>& b) {
    vector<int> v2;
    vector<bool> v1(a.size() + 1, false);
    
    for (int i = 0; i < b.size(); i++) {
        if (v2.empty() || (v2.back() != b[i] && !v1[b[i]])) {
            v2.push_back(b[i]);
            v1[b[i]] = true;
        }
    }

    if (v2.size() > a.size()) {
        return false;
    }

    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] != a[i]) {
            return false;
        }
    }
   
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;  // q will always be 0

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << (isGood(a, b) ? "YA" : "TIDAK") << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        // For n=1 or n=2, it's impossible to satisfy the conditions
        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }
        
        // Number of valid ways is (n-1)/2
        // Because:
        // 1. a must be > n/2
        // 2. b must be > 0
        // 3. a + b = n
        // Therefore, valid values for a are from (n+1)/2 to n-1
        cout << (n - 1) / 2 << endl;
    }
    return 0;
}

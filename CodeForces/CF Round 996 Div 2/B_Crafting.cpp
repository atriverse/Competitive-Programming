#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
private:
    int n;
    vector<ll> a, b;

public:
    void readInput() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
    }
    
    string checkCrafting() {
        ll maxDiff = 0;
        int maxDiffIndex = 0;
        
        // Find material with maximum deficit
        for(int i = 0; i < n; i++) {
            if(a[i] < b[i] && abs(a[i] - b[i]) >= maxDiff) {
                maxDiffIndex = i;
                maxDiff = abs(a[i] - b[i]);
            }
        }
        
        // Check if other materials can support the operations
        for(int i = 0; i < n; i++) {
            if(i != maxDiffIndex && a[i] - maxDiff < b[i]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    Solution solver;
    while(t--) {
        solver.readInput();
        cout << solver.checkCrafting() << "\n";
    }
    
    return 0;
}

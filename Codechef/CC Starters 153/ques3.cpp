#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& P) {
    int N = P.size();
    int K = 0;
    
    for (int i = 0; i < N; i++) {
        if (P[i] != i + 1) {
            K = max(K, max(P[i], i + 2));
        }
    }
    
    return K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        
        cout << solve(P) << "\n";
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
const int MAXBIT = 20;  // log2(10^6) ≈ 19.93

long long countValidQuadruples(const vector<int>& A) {
    int N = A.size();
    vector<int> count(1 << MAXBIT, 0);
    long long result = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int xor_val = A[i] ^ A[j];
            result += count[xor_val];
            count[xor_val]++;
        }
    }

    return result * 8;  // Multiply by 8 for all permutations
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << countValidQuadruples(A) << "\n";
    }

    return 0;
}

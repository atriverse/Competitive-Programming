#include <bits/stdc++.h>
using namespace std;

long long solveTestCase() {
    int N, M;
    cin >> N >> M;

    vector<string> strings(M);
    for (int i = 0; i < M; i++) {
        cin >> strings[i];
    }

    long long totalHammingDistance = 0;

    for (int j = 0; j < N; j++) {
        int count0 = 0, count1 = 0, countQ = 0;

        for (int i = 0; i < M; i++) {
            if (strings[i][j] == '0') count0++;
            else if (strings[i][j] == '1') count1++;
            else countQ++;
        }

        int max_count = max(count0, count1);
        int min_count = min(count0, count1);

        if (countQ > 0) {
            if (max_count >= (M / 2)) {
                min_count += countQ;
            } else {
                int half = (M + 1) / 2;
                if (max_count + countQ <= half) {
                    max_count += countQ;
                } else {
                    min_count += (max_count + countQ) - half;
                    max_count = half;
                }
            }
        }

        totalHammingDistance += (long long)max_count * min_count;
    }

    return totalHammingDistance;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long result = solveTestCase();
        cout << result << endl;
    }

    return 0;
}
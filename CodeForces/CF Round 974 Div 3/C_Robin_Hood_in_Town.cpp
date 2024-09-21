#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(int n, vector<long long>& wealth) {
    long long sum = 0;
    long long max_wealth = 0;
    for (int i = 0; i < n; i++) {
        sum += wealth[i];
        max_wealth = max(max_wealth, wealth[i]);
    }

    // Check if Robin Hood appears immediately
    long long avg = (sum + n - 1) / n; // Ceiling division
    int unhappy_count = 0;
    for (int i = 0; i < n; i++) {
        if (wealth[i] < (avg + 1) / 2) { // Ceiling division
            unhappy_count++;
        }
    }
    if (unhappy_count > n / 2) {
        return 0;
    }

    // If n = 1 or n = 2, Robin Hood can't appear
    if (n <= 2) {
        return -1;
    }

    long long left = 1, right = 1e18;
    long long result = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long new_sum = sum + mid;
        long long new_avg = (new_sum + n - 1) / n; // Ceiling division

        unhappy_count = 0;
        for (int i = 0; i < n; i++) {
            if (wealth[i] < (new_avg + 1) / 2) { // Ceiling division
                unhappy_count++;
            }
        }

        if (unhappy_count > n / 2) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> wealth(n);
        for (int i = 0; i < n; i++) {
            cin >> wealth[i];
        }

        cout << solve(n, wealth) << endl;
    }

    return 0;
}

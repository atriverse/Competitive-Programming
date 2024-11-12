#include <iostream>
#include <vector>

using namespace std;

void solve_test_case() {
    int n;
    cin >> n;
    
    vector<int> round_numbers;
    int multiplier = 1;
    int temp = n;
    
    // Store numbers from right to left
    while (temp > 0) {
        if (temp % 10 > 0) {
            round_numbers.push_back((temp % 10) * multiplier);
        }
        temp /= 10;
        multiplier *= 10;
    }
    
    // Output
    cout << round_numbers.size() << '\n';
    // For numbers with 4 digits, print largest first
    if (n >= 1000) {
        cout << round_numbers.back() << " ";
        for (int i = 0; i < round_numbers.size() - 1; i++) {
            cout << round_numbers[i];
            if (i < round_numbers.size() - 2) {
                cout << " ";
            }
        }
    } else {
        // For smaller numbers, print in original order
        for (int i = round_numbers.size() - 1; i >= 0; i--) {
            cout << round_numbers[i];
            if (i > 0) {
                cout << " ";
            }
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve_test_case();
    }
    
    return 0;
}

//Was not  able to solve this question
//Editorial
/*
We can rewrite x as |a1+⋯+ai−(ai+1+⋯+an)|. Essentially, we want to minimize the absolute value difference between the sums of the prefix and the suffix. With absolute value problems. it's always good to consider the positive and negative cases separately. We will consider the prefix greater than the suffix separately with the less than case.
We can use binary search to search for the greatest i such that a1+⋯+ai≤ai+1+⋯+an. Note that here, the positive difference is minimized. If we move to i+1, then the negative difference is minimized (since the sum of prefix will now be less than the sum of suffix). The answer is the minimum absolute value of both cases.
To evaluate a1+⋯+ai fast, we can use the sum of arithmetic sequence formula.
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
// Function to calculate the sum of numbers from l to r
int fnc(int l, int r) {
    return (r * (r + 1)) / 2 - (l * (l + 1)) / 2;
}
 
// Binary search function to find the minimal absolute difference
int bin(int low, int high, int n, int k) {
    int mid = -1, a = fnc(0, high);
 
    while (low <= high) {
        mid = (low + high) / 2;
        int v = fnc(k-1, mid) - fnc(mid, n + k - 1);
 
        a = min(a, abs(v));
 
        if (v == 0) {
            return v;
        } else if (v < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return a;
}
 
// Main function to handle multiple test cases
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << bin(k, n + k - 1, n, k) << endl;
    }
}
 
int32_t main() {
    
    solve();
    return 0;
}
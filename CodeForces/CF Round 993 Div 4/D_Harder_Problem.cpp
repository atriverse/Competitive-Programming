#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> buildResult(int n, vector<int>& nums) {
        vector<int> freq(n + 2);
        vector<int> result(n);
        int maxFreq = 0;
        int nextAvailable = 1;
        
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            
            if (i == 0 || freq[curr] < maxFreq) {
                result[i] = curr;
                freq[curr]++;
                maxFreq = max(maxFreq, freq[curr]);
            } else {
                if (maxFreq == 0) {
                    result[i] = curr;
                    freq[curr]++;
                    maxFreq = 1;
                    continue;
                }
                
                while (nextAvailable <= n && (freq[nextAvailable] > 0 || nextAvailable == curr)) {
                    nextAvailable++;
                }
                
                if (nextAvailable <= n && freq[nextAvailable] < maxFreq) {
                    result[i] = nextAvailable;
                    freq[nextAvailable]++;
                } else {
                    result[i] = curr;
                    freq[curr]++;
                    maxFreq = max(maxFreq, freq[curr]);
                }
            }
        }
        return result;
    }

public:
    void solve(int n, vector<int>& nums) {
        vector<int> result = buildResult(n, nums);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    
    Solution solver;
    while (testCases--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int& x : nums) {
            cin >> x;
        }
        
        solver.solve(n, nums);
    }
    return 0;
}

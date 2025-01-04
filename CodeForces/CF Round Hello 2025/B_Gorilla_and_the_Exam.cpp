#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> sortByFrequency(vector<int>& nums) {
    // Create frequency map
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Custom comparator for sorting
    auto compareFreq = [&freqMap](int a, int b) {
        if (freqMap[a] != freqMap[b]) {
            return freqMap[a] < freqMap[b];  // Sort by frequency
        }
        return a < b;  // If frequencies are equal, sort by value
    };
    
    // Sort using the custom comparator
    sort(nums.begin(), nums.end(), compareFreq);
    
    return nums;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sortByFrequency(a);

        int ans=0;
        int x=a[k];
        ans++;
        for(int i = k+1; i < n; i++) {
            if(a[i]==x)continue;
            else{
                ans++;
                x=a[i];
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}

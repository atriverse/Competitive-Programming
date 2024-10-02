//TLE
#include <bits/stdc++.h>
using namespace std;

long long triangleCount(vector<long long>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    map<long long, long long> events;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long min_x = abs(arr[i] - arr[j]) + 1;
            long long max_x = arr[i] + arr[j] - 1;
            
            events[min_x]++;
            events[max_x + 1]--;
        }
    }

    long long result = 0;
    long long current = 0;
    long long prev_x = 0;

    for (const auto& event : events) {
        if (current > 0) {
            result += event.first - prev_x;
        }
        current += event.second;
        prev_x = event.first;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << triangleCount(arr) << "\n";
    }
    
    return 0;
}

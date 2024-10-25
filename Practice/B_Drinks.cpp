#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double sum = 0;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sum += p;
    }
    
    // Calculate average percentage
    double result = sum / n;
    
    // Print with high precision
    cout << fixed << setprecision(12) << result << endl;
    
    return 0;
}

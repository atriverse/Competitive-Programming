#include <bits/stdc++.h>
using namespace std;

int main() {
    string guest, host, pile;
    cin >> guest >> host >> pile;
    
    // Combine guest and host names
    string combined = guest + host;
    
    // Sort both strings to compare
    sort(combined.begin(), combined.end());
    sort(pile.begin(), pile.end());
    
    // Check if the sorted strings are equal
    if (combined == pile) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

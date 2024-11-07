#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> uniforms(n);
    
    // Read home and away colors for each team
    for (int i = 0; i < n; i++) {
        cin >> uniforms[i].first >> uniforms[i].second;
    }
    
    int count = 0;
    
    // Check each possible game combination
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {  // Teams don't play against themselves
                // If home team's home uniform matches guest team's away uniform
                if (uniforms[i].first == uniforms[j].second) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}

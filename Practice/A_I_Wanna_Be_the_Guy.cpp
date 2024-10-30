#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Create a set to store unique levels that can be passed
    set<int> levels;
    
    // Read Little X's levels
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
        int level;
        cin >> level;
        levels.insert(level);
    }
    
    // Read Little Y's levels
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int level;
        cin >> level;
        levels.insert(level);
    }
    
    // Check if they can pass all levels together
    if(levels.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    
    return 0;
}

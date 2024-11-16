#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int amazing = 0;
    int score;
    cin >> score;  // first score
    
    int max_score = score;
    int min_score = score;
    
    // Process remaining scores
    for (int i = 1; i < n; i++) {
        cin >> score;
        
        // Check if current score breaks any record
        if (score > max_score) {
            amazing++;
            max_score = score;
        }
        else if (score < min_score) {
            amazing++;
            min_score = score;
        }
    }
    
    cout << amazing << endl;
    return 0;
}

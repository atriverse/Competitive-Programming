#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int available_officers = 0;  // tracks current available police officers
    int untreated_crimes = 0;    // tracks crimes that went untreated
    
    for(int i = 0; i < n; i++) {
        int event;
        cin >> event;
        
        if(event > 0) {
            // New officers are recruited
            available_officers += event;
        } else {
            // Crime occurs
            if(available_officers > 0) {
                // If officers are available, one will handle the crime
                available_officers--;
            } else {
                // No officers available, crime goes untreated
                untreated_crimes++;
            }
        }
    }
    
    cout << untreated_crimes << endl;
    return 0;
}

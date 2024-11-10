#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // For odd numbered rows, print all #
            if(i % 2 == 1) {
                cout << "#";
            }
            // For even numbered rows
            else {
                // If row number divided by 4 gives remainder 2
                // Print # at last position
                if(i % 4 == 2) {
                    cout << (j == m ? "#" : ".");
                }
                // If row number divided by 4 gives remainder 0
                // Print # at first position
                else {
                    cout << (j == 1 ? "#" : ".");
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}

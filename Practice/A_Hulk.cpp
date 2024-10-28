#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    cout << "I hate";
    
    for(int i = 2; i <= n; i++) {
        cout << " that I ";
        if(i % 2 == 0) {
            cout << "love";
        } else {
            cout << "hate";
        }
    }
    
    cout << " it" << endl;
    
    return 0;
}

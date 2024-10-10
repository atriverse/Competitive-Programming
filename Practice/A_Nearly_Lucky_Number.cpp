#include <iostream>
#include <string>

using namespace std;

bool isLucky(int num) {
    return num == 4 || num == 7;
}

int main() {
    string n;
    cin >> n;
    
    int luckyCount = 0;
    for (char digit : n) {
        if (digit == '4' || digit == '7') {
            luckyCount++;
        }
    }
    
    if (isLucky(luckyCount)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

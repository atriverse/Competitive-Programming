#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BitManipulator {
private:
    int leftNumber;
    int rightNumber;
    int position;
    int result;

public:
    BitManipulator(int left, int right) : 
        leftNumber(left), 
        rightNumber(right), 
        position(0), 
        result(0) {}

    void calculate() {
        for (int bit = 29; bit >= 0; bit--) {
            if ((rightNumber & (1 << bit)) != (leftNumber & (1 << bit))) {
                result += (1 << bit);
                position = bit;
                break;
            } else {
                if (leftNumber & (1 << bit)) {
                    result += (1 << bit);
                }
            }
        }
    }

    void printResults() {
        cout << result << " " 
             << result - 1 << " " 
             << (result == rightNumber ? rightNumber - 2 : rightNumber) 
             << endl;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int left, right;
        cin >> left >> right;
        
        BitManipulator bitMan(left, right);
        bitMan.calculate();
        bitMan.printResults();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minOperations(int X, int Y, int Z) {

    if (Y - X == Z - Y) return 0;

    if ((X + Z) % 2 == 0) return 1;

    return 1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        cout << minOperations(X, Y, Z) << endl;
    }

    return 0;
}

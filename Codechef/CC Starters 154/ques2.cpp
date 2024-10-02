#include <bits/stdc++.h>
using namespace std;

string solve(int N) {
    if(N==1)return "ALICE";
    return "BOB";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}
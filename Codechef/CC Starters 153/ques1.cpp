#include <bits/stdc++.h>
using namespace std;

bool can_butterflies_feed(int R, int G, int B) {
    return (R <= G + B) && (G <= R + B) && (B <= R + G);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int R, G, B;
        cin >> R >> G >> B;

        if (can_butterflies_feed(R, G, B)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
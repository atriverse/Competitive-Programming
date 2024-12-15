#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // Count pairs where a = n-b and both a,b are positive integers
        int count = 0;
        for (int b = 1; b < n; b++) {
            int a = n - b;
            if (a > 0) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
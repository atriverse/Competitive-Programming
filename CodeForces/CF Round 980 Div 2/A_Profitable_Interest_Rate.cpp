#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if (a >= b)
        {
            cout << a << '\n';
            continue;
        }

        long long x = b - a;
        if (x <= a)
        {
            long long max_deposit = a - x;
            cout << max_deposit << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}

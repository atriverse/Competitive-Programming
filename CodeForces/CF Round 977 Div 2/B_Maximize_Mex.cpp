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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        set<int> unique_elements;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mx = max(mx, v[i]);
            unique_elements.insert(v[i]);
        }
        int potential_max = mx + (n - unique_elements.size()) + 1;
        vector<int> freq(potential_max + 1, 0);
        for (int i = 0; i < n; i++) {
            if (v[i] <= potential_max) {
                freq[v[i]]++;
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int i = 0;
        for (i = 0; i < n && i <= potential_max; i++)
        {
            if (v[i] != i && freq[i] == 0)
            {
                ans = i;
                break;
            }
            else if (v[i] == i) {
                continue;
            }
            else {
                int temp = x;
                while (freq[i] && i + temp <= potential_max) {
                    freq[i]--;
                    freq[i + temp]++;
                    temp += x;
                }
            }
        }
        if (i == n || i > potential_max) {
            ans = potential_max;
        }
        for (int j = i; j <= potential_max; j++)
        {
            if (freq[j] == 0)
            {
                ans = j;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

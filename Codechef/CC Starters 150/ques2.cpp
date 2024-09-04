#include <bits/stdc++.h>
using namespace std;

void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        deque<int> arr;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        for (int j = 0; j < k; j++)
        {
            int x = arr.front();
            arr.pop_front();
            int y = arr.back();
            arr.pop_back();
            arr.push_back(x + y);
        }
        showdq(arr);
    }
}

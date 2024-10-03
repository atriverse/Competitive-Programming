/*
Triangle Count (Easy)
This is the easy version of the problem. It is worth the usual 100 points in all divisions. Here, you need to solve the problem only for the entire array.

For an array B containing M distinct integers, say [B1 ,B2 ,…,BM], we define f(B) to be the number of distinct integers X that satisfy the following conditions:

X≥1; and
There exists 1≤i<j≤M such that it is possible to form a non-degenerate triangle with side lengths
(Bi,Bj,X).
A non-degenerate triangle is one with positive area.
You are given an array A containing N distinct integers. Find f(A).

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer N — the size of the arra The second line contains N space-separated integers A1 ,A2  ,…,AN  .
Output Format
For each test case, output on a new line one integer: f(A).

Constraints
1≤T≤10^4
1≤N≤2⋅10^5
1≤Ai≤10^9
Ai!=Aj  wheneveri!=j
The sum of N across all tests does not exceed 2⋅10^5.
Sample 1:
Input
5
2
5 2
3
5 2 4
4
5 2 4 12
6
3 1 6 5 50 17
3
100 2 69
Output
3
7
15
53
137
Explanation:
Test case 1: The 3 valid values of X are 4,5, and 6.
*/

// Explanation:
/*
The logic flow is as follows:

    -> Sort the input array.
    -> For each pair of adjacent numbers in the sorted array, calculate two ranges: a) When X is the largest side of the triangle. b) When X is not the largest side of the triangle.
    -> Store these ranges in a set, which automatically sorts them.
    -> Merge overlapping ranges and count the number of integer points within these ranges.
An important data transformation happens when the code converts the problem of checking individual X values into a problem of managing ranges of valid X values. This significantly reduces the computation time, especially for large inputs.

The final answer is calculated by counting the number of integer points in the merged ranges, which represents all possible X values that can form valid triangles with the given side lengths.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;

    while (tt--)
    {
        int n, answer = 0;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        sort(a.begin(), a.end());

        set<pair<int, int>> ranges;

        auto update = [&](int l, int r) -> void
        {
            ranges.insert({l, r});
        };

        for (int i = 1; i < n; i++)
        {
            update(a[i], a[i] + a[i - 1] - 1); // x is the largest element
            update(a[i] - a[i - 1] + 1, a[i]); // xis not largest element
        }

        // merging the intervals and counting the number of elements in the range
        int left = 1;

        for(auto it = ranges.begin(); it != ranges.end(); ++it) {
            int l = it->first;
            int r = it->second;
            answer += max(0ll, r - max(l, left) + 1);
            left = max(left, r + 1);
        }


        cout << answer << "\n";
    }
}

/*
//TLE -> Brute force with TC of O(n^2)
#include <bits/stdc++.h>
using namespace std;

long long triangleCount(vector<long long>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    map<long long, long long> events;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long min_x = abs(arr[i] - arr[j]) + 1;
            long long max_x = arr[i] + arr[j] - 1;

            events[min_x]++;
            events[max_x + 1]--;
        }
    }

    long long result = 0;
    long long current = 0;
    long long prev_x = 0;

    for (const auto& event : events) {
        if (current > 0) {
            result += event.first - prev_x;
        }
        current += event.second;
        prev_x = event.first;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << triangleCount(arr) << "\n";
    }

    return 0;
}
*/
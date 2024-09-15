/*
                                        Maximum multiplication score
You are given an integer array a of size 4 and another integer array b of size at least 4.

You need to choose 4 indices i0, i1, i2, and i3 from the array b such that i0 < i1 < i2 < i3. Your score will be equal to the value a[0] * b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3].

Return the maximum score you can achieve.

Example 1:

Input: a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]

Output: 26

Explanation:
We can choose the indices 0, 1, 2, and 5. The score will be 3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26.

Example 2:

Input: a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]

Output: -1

Explanation:
We can choose the indices 0, 1, 3, and 4. The score will be (-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1.

Constraints:

a.length == 4
4 <= b.length <= 105
-105 <= a[i], b[i] <= 105
*/
// Solution:
#include <bits/stdc++.h>
using namespace std;

// Using Recursion Memoization
class Solution
{
    #define ll long long
    vector<vector<ll>> dp;
    int n;
    /**
     * Recursively calculates the maximum score that can be obtained by selecting 4 indices from the `b` array and multiplying the corresponding elements from the `a` array.
     *
     * @param idx - The current index in the `b` array.
     * @param g - The number of elements that have been selected so far.
     * @param a - An integer array of size 4 containing the values to be multiplied.
     * @param b - An integer array of at least size 4 containing the values to be selected from.
     * @return The maximum score that can be obtained by selecting 4 indices from the `b` array.
     */
    ll helper(int idx, int g, vector<int> &a, vector<int> &b)
    {
        if (g == 4)
            return 0;
        if (idx == n)
            return -1e12;
        if (dp[idx][g] != -1e12)
            return dp[idx][g];
        ll ans1 = helper(idx + 1, g, a, b);
        ll ans2 = helper(idx + 1, g + 1, a, b) + a[g] * 1LL * b[idx];
        return dp[idx][g] = max(ans1, ans2);
    }

public:
    /**
     * Calculates the maximum score that can be obtained by selecting 4 indices from the `b` array and multiplying the corresponding elements from the `a` array.
     *
     * @param a - An integer array of size 4 containing the values to be multiplied.
     * @param b - An integer array of at least size 4 containing the values to be selected from.
     * @return The maximum score that can be obtained.
     */
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        n = b.size();
        dp = vector<vector<ll>>(n, vector<ll>(4, -1e12));
        return helper(0, 0, a, b);
    }
};

// Using Tabulation
class Solution1
{
public:
    /**
     * Calculates the maximum score that can be obtained by selecting 4 indices from the `b` array and multiplying the corresponding elements from the `a` array.
     *
     * This function uses dynamic programming to solve the problem. It iterates through the `b` array and keeps track of the maximum score that can be obtained by selecting up to 4 elements from the `b` array. The score is calculated by multiplying the corresponding elements from the `a` array.
     *
     * @param a - An integer array of size 4 containing the values to be multiplied.
     * @param b - An integer array of at least size 4 containing the values to be selected from.
     * @return The maximum score that can be obtained.
     */
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        int n = b.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(5, numeric_limits<long long>::min()));

        // Base case: when we have selected 0 elements, the score is 0
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 4 && j <= i; j++)
            {
                // Option 1: Don't select the current element
                dp[i][j] = dp[i - 1][j];

                // Option 2: Select the current element
                long long score = (1ll * a[j - 1]) * (1ll * b[i - 1]) + dp[i - 1][j - 1];
                dp[i][j] = max(dp[i][j], score);
            }
        }

        return dp[n][4];
    }
};

int main()
{
    Solution s;
    vector<int> a = {3, 2, 5, 6};
    vector<int> b = {2, -6, 4, -5, -3, 2, -7};
    cout << s.maxScore(a, b) << endl;
    Solution1 s1;
    cout << s1.maxScore(a, b) << endl;
    return 0;
}
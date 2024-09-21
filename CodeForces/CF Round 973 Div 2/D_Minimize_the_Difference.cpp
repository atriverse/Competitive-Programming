/*
D. Minimize the Difference
time limit per test2 seconds
memory limit per test256 megabytes
Zhan, tired after the contest, gave the only task that he did not solve during the contest to his friend, Sungat. However, he could not solve it either, so we ask you to try to solve this problem.

You are given an array a1,a2,…,an of length n. We can perform any number (possibly, zero) of operations on the array.

In one operation, we choose a position i (1≤i≤n−1) and perform the following action:

ai:=ai−1, and ai+1:=ai+1+1.
Find the minimum possible value of max(a1,a2,…,an)−min(a1,a2,…,an).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤2⋅105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1012).

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer: the minimum possible value of max(a1,a2,…,an)−min(a1,a2,…,an).

Example
Input
5
1
1
3
1 2 3
4
4 1 2 3
4
4 2 3 1
5
5 14 4 10 2
Output
0
2
1
1
3
Note
In the third testcase, you can perform the operation twice with i=1.

After that, the array is a=[2,3,2,3], and max(2,3,2,3)−min(2,3,2,3)=3−2=1.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> heights;

/**
 * Checks if it is possible to set the maximum height of the buildings to the given `height` value.
 *
 * The function calculates the total excess height that would be required to raise all buildings to the
 * given `height` value. If the total excess height is 0, it means it is possible to set the maximum
 * height to the given value.
 *
 * @param height The height value to check for.
 * @return `true` if it is possible to set the maximum height to the given value, `false` otherwise.
 */
bool isValidMaxHeight(int height)
{
    int excess = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] > height)
        {
            excess += heights[i] - height;
        }
        else
        {
            excess = max(0LL, excess - (height - heights[i]));
        }
    }
    return excess == 0;
}

/**
 * Finds the maximum height that can be set for all buildings such that the difference between the
 * maximum and minimum heights is minimized.
 *
 * The function uses a binary search approach to find the maximum height that satisfies the condition
 * that the total excess height required to raise all buildings to that height is 0. The search
 * starts with the range [0, 1e12] and narrows down the search space until the maximum height is found.
 *
 * @return The maximum height that can be set for all buildings such that the difference between the
 * maximum and minimum heights is minimized.
 */
int findMaxHeight()
{
    int left = 0, right = 1e12, result = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isValidMaxHeight(mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

/**
 * Checks if it is possible to set the minimum height of all buildings to the given value.
 *
 * The function calculates the total excess height required to raise all buildings to the given height.
 * If the total excess height is non-negative, it means it is possible to set the minimum height to the
 * given value. The function returns `true` in this case, and `false` otherwise.
 *
 * @param height The height value to check for.
 * @return `true` if it is possible to set the minimum height to the given value, `false` otherwise.
 */
bool isValidMinHeight(int height)
{
    int excess = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] >= height)
        {
            excess += heights[i] - height;
        }
        else
        {
            excess -= height - heights[i];
            if (excess < 0)
                return false;
        }
    }
    return true;
}

/**
 * Finds the minimum height that can be set for all buildings such that the difference between the
 * maximum and minimum heights is minimized.
 *
 * The function uses a binary search approach to find the minimum height. It starts with a search
 * range of [0, 1e12] and narrows down the range based on the result of the `isValidMinHeight`
 * function. The function returns the minimum height that satisfies the condition.
 *
 * @return The minimum height that can be set for all buildings such that the difference between the
 * maximum and minimum heights is minimized.
 */
int findMinHeight()
{
    int left = 0, right = 1e12, result = left;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isValidMinHeight(mid))
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

/**
 * The main entry point of the program.
 * 
 * This function reads in a number of test cases, and for each test case:
 * 1. Reads in the number of buildings `n`.
 * 2. Reads in the heights of the `n` buildings.
 * 3. Calls the `findMaxHeight` and `findMinHeight` functions to determine the maximum and minimum heights that can be set for all buildings such that the difference between the maximum and minimum heights is minimized.
 * 4. Prints the difference between the maximum and minimum heights.
 *
 * @return 0 on successful completion.
 */
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int n;
        cin >> n;

        heights.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        int maxHeight = findMaxHeight();
        int minHeight = findMinHeight();

        cout << maxHeight - minHeight << "\n";
    }

    return 0;
}

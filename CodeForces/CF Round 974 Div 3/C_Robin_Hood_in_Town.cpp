/*
C. Robin Hood in Town
time limit per test2 seconds
memory limit per test256 megabytes
In Sherwood, we judge a man not by his wealth, but by his merit.
Look around, the rich are getting richer, and the poor are getting poorer. We need to take from the rich and give to the poor. We need Robin Hood!

There are n people living in the town. Just now, the wealth of the i-th person was ai gold. But guess what? The richest person has found an extra pot of gold!

More formally, find an aj=max(a1,a2,…,an), change aj to aj+x, where x is a non-negative integer number of gold found in the pot. If there are multiple maxima, it can be any one of them.
A person is unhappy if their wealth is strictly less than half of the average wealth∗.

If strictly more than half of the total population n are unhappy, Robin Hood will appear by popular demand.

Determine the minimum value of x for Robin Hood to appear, or output −1 if it is impossible.
∗
The average wealth is defined as the total wealth divided by the total population n, that is, ∑ain, the result is a real number.

Input
The first line of input contains one integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤2⋅105) — the total population.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the wealth of each person.

It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

Output
For each test case, output one integer — the minimum number of gold that the richest person must find for Robin Hood to appear. If it is impossible, output −1 instead.

Example
Input
6
1
2
2
2 19
3
1 3 20
4
1 2 3 4
5
1 2 3 4 5
6
1 2 1 1 1 25
Output
-1
-1
0
15
16
0
Note
In the first test case, it is impossible for a single person to be unhappy.

In the second test case, there is always 1 happy person (the richest).

In the third test case, no additional gold are required, so the answer is 0.

In the fourth test case, after adding 15 gold, the average wealth becomes 254, and half of this average is 258, resulting in 3 people being unhappy.

In the fifth test case, after adding 16 gold, the average wealth becomes 315, resulting in 3 people being unhappy.
*/

//My Solution
/*
The function achieves its purpose through several steps:

First, it checks if there are 2 or fewer people in the town. If so, it's impossible for Robin Hood to appear, so the function returns -1.

Next, it calculates the total wealth of the town and finds the maximum wealth among all individuals. It then checks if Robin Hood would appear immediately without any additional gold. This is done by calculating the average wealth and counting how many people are unhappy (those with less than half the average wealth). If more than half the population is already unhappy, the function returns 0.

If Robin Hood doesn't appear immediately, the function uses a binary search algorithm to find the minimum amount of gold needed. It repeatedly guesses an amount of gold (starting with a range from 1 to 10^18), adds this to the total wealth, recalculates the average, and counts the unhappy people. If more than half are unhappy, it records this amount and tries a smaller amount. If not, it tries a larger amount. This process continues until it finds the smallest amount of gold that makes Robin Hood appear.

The most important logic flow in this code is the binary search loop. It efficiently narrows down the correct amount of gold by halving the search range in each iteration. The data transformation happening here is the constant recalculation of the new total wealth, new average wealth, and the count of unhappy people based on the current guess of additional gold.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Finds the minimum number of gold that the richest person must find for Robin Hood to appear.
 *
 * @param n The total population.
 * @param wealth A vector of the wealth of each person.
 * @return The minimum number of gold that the richest person must find, or -1 if it is impossible.
 */
long long solve(int n, vector<long long>& wealth) {
    // If n = 1 or n = 2, Robin Hood can't appear
    if (n <= 2) {
        return -1;
    }
    // Calculate the sum of all wealth and find the maximum wealth
    long long sum = 0;
    long long max_wealth = 0;
    for (int i = 0; i < n; i++) {
        sum += wealth[i];
        max_wealth = max(max_wealth, wealth[i]);
    }

    // Check if Robin Hood appears immediately
    long long avg = (sum + n - 1) / n; // Ceiling division
    int unhappy_count = 0;
    for (int i = 0; i < n; i++) {
        if (wealth[i] < (avg + 1) / 2) { // Ceiling division
            unhappy_count++;
        }
    }
    if (unhappy_count > n / 2) {
        return 0;
    }

    long long left = 1, right = 1e18;
    long long result = -1;

    // Binary search for the minimum number of gold that the richest person must find
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long new_sum = sum + mid;
        long long new_avg = (new_sum + n - 1) / n; // Ceiling division

        unhappy_count = 0;
        for (int i = 0; i < n; i++) {
            if (wealth[i] < (new_avg + 1) / 2) { // Ceiling division
                unhappy_count++;
            }
        }

        if (unhappy_count > n / 2) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> wealth(n);
        for (int i = 0; i < n; i++) {
            cin >> wealth[i];
        }

        cout << solve(n, wealth) << endl;
    }

    return 0;
}

//Editorial Solution
/*
If we sort the wealth in increasing order, then the j-th person must be unhappy for Robin to appear, where j=⌊n/2⌋+1 if 1-indexing or j=⌊n/2⌋ if 0-indexing. We need aj<s+x2∗n, where s is the original total wealth before x gold from the pot was added. Rearranging the equation gives x>2∗n∗aj−s. Because x is a non-negative integer, we arrive at the answer max(0,2∗n∗aj−s+1).

Of course, this problem can also be solved by binary search, with two caveats. First, one needs to be careful to avoid comparison between integer and float types, as rounding errors could create issues. You can always avoid division by 2n by multiplying it out. Second, one needs to pick the upper limit carefully to ensure it is large enough. Note that 2∗n∗max(a) can serve as the upper limit for the binary search for x, because that would push the average to be strictly above 2∗max(a) and everyone except the one with the pot of gold would be unhappy.

There are 2 edge cases, n=1,2, where the condition for Robin can never be reached, because the richest person will always be happy (at least in this problem, though perhaps not IRL). ChatGPT struggled to identify these edge cases, so it was tempting to leave at least one hidden. Following testing, we decided to give both in samples to reduce frustration.

Note: Wealth inequality is better measured by the Gini coefficient which is too involved for this problem. Our criterion is a crude approximation for the Gini coefficient, and is equivalent to setting the mean to median ratio (a well known indicator for inequality) to 2. For a random distribution, this ratio is close to 1. Interestingly, this ratio for UK salary distribution is around 1.2, so no Robin yet.

void work(){
    int n;
    cin >> n;
    
    long long sum = 0;
    vector<long long> v(n);
    for (auto &c : v) cin >> c, sum += c;
 
    sort(v.begin(),v.end());
 
    if (n < 3){
        cout << "-1\n";
        return;
    }
    cout << max(0LL,v[n/2]*2*n-sum+1) << '\n';
}
*/
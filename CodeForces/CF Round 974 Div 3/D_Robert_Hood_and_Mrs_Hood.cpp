/*
D. Robert Hood and Mrs Hood
time limit per test2 seconds
memory limit per test256 megabytes
Impress thy brother, yet fret not thy mother.
Robin's brother and mother are visiting, and Robin gets to choose the start day for each visitor.

All days are numbered from 1 to n. Visitors stay for d continuous days, all of those d days must be between day 1 and n inclusive.

Robin has a total of k risky 'jobs' planned. The i-th job takes place between days li and ri inclusive, for 1≤i≤k. If a job takes place on any of the d days, the visit overlaps with this job (the length of overlap is unimportant).

Robin wants his brother's visit to overlap with the maximum number of distinct jobs, and his mother's the minimum.

Find suitable start days for the visits of Robin's brother and mother. If there are multiple suitable days, choose the earliest one.

Input
The first line of the input contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case consists of three integers n, d, k (1≤n≤105,1≤d,k≤n) — the number of total days, duration of the visits, and the number of jobs.

Then follow k lines of each test case, each with two integers li and ri (1≤li≤ri≤n) — the start and end day of each job.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output two integers, the best starting days of Robin's brother and mother respectively. Both visits must fit between day 1 and n inclusive.

Example
Input
6
2 1 1
1 2
4 1 2
1 2
2 4
7 2 3
1 2
1 3
6 7
5 1 2
1 2
3 5
9 2 1
2 8
9 2 4
7 9
4 8
1 3
2 3
Output
1 1
2 1
1 4
1 1
1 1
3 4
Note
In the first test case, the only job fills all 2 days, both should visit on day 1.

In the second test case, day 2 overlaps with 2 jobs and day 1 overlaps with only 1.

In the third test case, Robert visits for days [1,2], Mrs. Hood visits for days [4,5].
*/

// Editorial Solution
/*
Since the number of days n is capped, we can check all possible start day x in range [1,n−d+1] (so that the duration of d days would fit). We would like to find the number of overlapped jobs for each value of x.

A job between days li and ri would overlap with the visit if the start day x satisfies li−d+1≤x≤ri. Naively, this range update could be potentially O(n), which is too slow. However, noting the start and end, each job update could be done in 2 operations. We add +1 at li−d+1 and −1 at ri+1, and after all jobs are recorded, we will take a prefix sum to work out the number of overlapped jobs for each x. When li−d+1 drops below 1, we simply use 1 to avoid lower values which are not being considered for x.

The time complexity is O(n).

Note: Robin's risky jobs are generally deemed illegal by the Sheriff of Nottingham. Robert is practical and helpful. Like all good parents, Mrs Hood is a worrier.
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*
The purpose of this code is to find the best starting days for Robert's and Mrs. Hood's visits. Robert's visit should overlap with the maximum number of jobs, while Mrs. Hood's visit should overlap with the minimum number of jobs.

To achieve this, the function uses a clever technique called prefix sum. It creates two arrays, 'ss' and 'es', to keep track of the start and end days of jobs. As it reads each job's start and end day, it increments the corresponding positions in these arrays.

Next, it calculates the cumulative sum for both arrays. This step transforms the arrays so that each position now represents the total number of jobs that have started or ended up to that day.

The function then iterates through all possible starting days for the visits. For each day, it calculates how many jobs overlap with a visit starting on that day by subtracting the number of jobs that ended before the visit from the number of jobs that started by the last day of the visit.

As it iterates, it keeps track of the day that results in the maximum number of overlapping jobs (for Robert) and the minimum number of overlapping jobs (for Mrs. Hood).

Finally, the function outputs two numbers: the best starting day for Robert's visit and the best starting day for Mrs. Hood's visit.
 */
void work(){
    int n,k,d;
    cin >> n >> d >> k;
 
    vector<int> ss(n+1),es(n+1);
 
    for (int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        ss[a]++;
        es[b]++;
    }
 
    for (int i=0;i<n;i++) ss[i+1] += ss[i];
    for (int i=0;i<n;i++) es[i+1] += es[i];
 
    int most = 0;
    int robert = 0;
    int mrs = 0;
    int least = 1e9;
    for (int i=d;i<=n;i++){
        int cur = ss[i] - es[i-d];
        if (cur > most) most = cur, robert = i-d+1;
        if (cur < least) least = cur, mrs = i-d+1;
    }
 
    cout << robert << ' ' << mrs << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        work();
    }

    return 0;
}
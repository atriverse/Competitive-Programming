/*
C1. Adjust The Presentation (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the easy version of the problem. In the two versions, the constraints on q and the time limit are different. In this version, q=0. You can make hacks only if all the versions of the problem are solved.

A team consisting of n members, numbered from 1 to n, is set to present a slide show at a large meeting. The slide show contains m slides.

There is an array a of length n. Initially, the members are standing in a line in the order of a1,a2,…,an from front to back. The slide show will be presented in order from slide 1 to slide m. Each section will be presented by the member at the front of the line. After each slide is presented, you can move the member at the front of the line to any position in the lineup (without changing the order of the rest of the members). For example, suppose the line of members is [3,1,2,4]. After member 3 presents the current slide, you can change the line of members into either [3,1,2,4], [1,3,2,4], [1,2,3,4] or [1,2,4,3].
There is also an array b of length m. The slide show is considered good if it is possible to make member bi present slide i for all i from 1 to m under these constraints.

However, your annoying boss wants to make q updates to the array b. In the i-th update, he will choose a slide si and a member ti and set bsi:=ti. Note that these updates are persistent, that is changes made to the array b will apply when processing future updates.

For each of the q+1 states of array b, the initial state and after each of the q updates, determine if the slideshow is good.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains three integers n, m and q (1≤n,m≤2⋅105; q=0) — the number of members, the number of sections and the number of updates.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the initial order of the members from front to back. It is guaranteed that each integer from 1 to n appears exactly once in a.

The third line of each test case contains m integers b1,b2,…,bm (1≤bi≤n) — the members who should present each section.

It is guaranteed that the sum of n and the sum of m over all test cases do not exceed 2⋅105 respectively.

Output
For each test case, output q+1 lines corresponding to the q+1 states of the array b. Output "YA" if the slide show is good, and "TIDAK" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yA", "Ya", "ya", and "YA" will be recognized as positive responses.

Example
Input
3
4 2 0
1 2 3 4
1 1
3 6 0
1 2 3
1 1 2 3 3 2
4 6 0
3 1 4 2
3 1 1 2 3 4
Output
YA
YA
TIDAK
Note
For the first test case, you do not need to move the members as both slides are presented by member 1, who is already at the front of the line.

For the second test case, the following is a possible way to move members so that the presentation is good:

[1,2,3], do not move member 1.[1,2,3], move member 1 after member 3.[2,3,1], move member 2 after member 3.[3,2,1], do not move member 3.[3,2,1], move member 3 after member 1.[2,1,3], do not move member 2.


*/

// Editorial:
/*
2021C2 - Adjust The Presentation (Hard Version)
Let's solve the problem if there is no update. The front member of the initial lineup must do the presentation first no matter what. After the front member is done with their presentation, we need to move the member to some position. Turns out, we do not need to care which position the member will be moved to. For every member that is done with their presentation, put the member in some set S then remove them from the lineup. We can put the member later from S to the front of the lineup if there is a section where they must present at that time. Therefore, we can iterate each section of the presentation, and check if the member is in S or in front of the current lineup, after some member is done with the presentation, put them to S and remove them from the lineup.
Observe that our strategy is equivalent to verifying whether the order of the first occurrences of elements a and b is consistent. Given that a is a permutation, we can simplify our approach by modifying array b based on a. Specifically, we only need to ensure that the first occurrence indices of the elements in b are in increasing order, starting from 1, 2, and so on, up to k≤n.

To determine whether the current array b is valid (i.e., "good"), we can construct a segment tree with n leaves. In this segment tree:
The value of the i-th leaf node represents the index of the first occurrence of element i in array b.
If element i does not appear in b, we assign the value m+i to the i-th leaf, where m is the length of array b.
With this setup, the leaf values will be in strictly increasing order if and only if b satisfies the required condition of being "good".

For each internal node in the segment tree, we store the following informations:

The smallest value within the range covered by the node.
The largest value within the range covered by the node.
A boolean indicator specifying whether the values within the range are strictly increasing.
This structure allows us to efficiently query and verify the increasing order of first occurrences across b, thereby determining the validity of b according to our strategy.

Time complexity for each test case: O(qlogn)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Checks if the given presentation order represented by the vector `b` is valid with respect to the initial order represented by the vector `a`.
 *
 * @param a The initial order of the members.
 * @param b The presentation order of the members.
 * @return `true` if the presentation order is valid, `false` otherwise.
 */
bool isGood(const vector<int> &a, const vector<int> &b)
{
    vector<int> v2;
    vector<bool> v1(a.size() + 1, false);

    for (int i = 0; i < b.size(); i++)
    {
        if (v2.empty() || (v2.back() != b[i] && !v1[b[i]]))
        {
            v2.push_back(b[i]);
            v1[b[i]] = true;
        }
    }

    if (v2.size() > a.size())
    {
        return false;
    }

    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i] != a[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q; // q will always be 0

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        cout << (isGood(a, b) ? "YA" : "TIDAK") << "\n";
    }

    return 0;
}

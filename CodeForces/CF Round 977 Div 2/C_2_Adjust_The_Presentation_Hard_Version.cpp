/*
C2. Adjust The Presentation (Hard Version)
time limit per test5 seconds
memory limit per test256 megabytes
This is the hard version of the problem. In the two versions, the constraints on q and the time limit are different. In this version, 0≤q≤2⋅105. You can make hacks only if all the versions of the problem are solved.

A team consisting of n members, numbered from 1 to n, is set to present a slide show at a large meeting. The slide show contains m slides.

There is an array a of length n. Initially, the members are standing in a line in the order of a1,a2,…,an from front to back. The slide show will be presented in order from slide 1 to slide m. Each section will be presented by the member at the front of the line. After each slide is presented, you can move the member at the front of the line to any position in the lineup (without changing the order of the rest of the members). For example, suppose the line of members is [3,1,2,4]. After member 3 presents the current slide, you can change the line of members into either [3,1,2,4], [1,3,2,4], [1,2,3,4] or [1,2,4,3].

There is also an array b of length m. The slide show is considered good if it is possible to make member bi present slide i for all i from 1 to m under these constraints.
However, your annoying boss wants to make q updates to the array b. In the i-th update, he will choose a slide si and a member ti and set bsi:=ti. Note that these updates are persistent, that is changes made to the array b will apply when processing future updates.

For each of the q+1 states of array b, the initial state and after each of the q updates, determine if the slideshow is good.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains three integers n, m and q (1≤n,m≤2⋅105; 0≤q≤2⋅105) — the number of members and the number of sections.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the initial order of the members from front to back. It is guaranteed that each integer from 1 to n appears exactly once in a.

The third line of each test case contains m integers b1,b2,…,bm (1≤bi≤n) — the members who should present each section.

Each of the next q lines contains two integers si and ti (1≤si≤m, 1≤ti≤n) — parameters of an update.

It is guaranteed that the sum of n, the sum of m and the sum of q over all test cases do not exceed 2⋅105 respectively.

Output
For each test case, output q+1 lines corresponding to the q+1 states of the array b. Output "YA" if the slide show is good, and "TIDAK" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yA", "Ya", "ya", and "YA" will be recognized as positive responses.

Example
Input
3
4 2 2
1 2 3 4
1 1
1 2
1 1
3 6 2
1 2 3
1 1 2 3 3 2
3 3
2 2
4 6 2
3 1 4 2
3 1 1 2 3 4
3 4
4 2
Output
YA
TIDAK
YA
YA
TIDAK
YA
TIDAK
YA
YA
Note
For the first test case, you do not need to move the members as both slides are presented by member 1, who is already at the front of the line. After that, set b1:=2, now slide 1 must be presented by member 2 which is impossible as member 1 will present slide 1 first. Then, set b1=1, the b is the same as the initial b, making a good presentation possible.
*/

// Editorial
/*
2021C2 - Adjust The Presentation (Hard Version)
Firstly, let's relabel the n members such that member number i is the i-th member in the initial line configuration in array a. We also adjust the values in b (and the future updates) accordingly.

For now, let's solve the problem if there are no updates to the array b. Consider the first member who presents. Notice that member 1 must be the first one presenting since he/she is at the very front of the line, which means b1=1 must hold. After this, we insert him/her into any position in the line. However, instead of determining the target position immediately, we make member 1 a "pending member" and we will only determine his/her position later on when we need him/her again.
To generalize, we can form an algorithm to check whether achieving b is possible or not. We iterate each element bi for each i from 1 to m. While iterating, we maintain a set of pending members which is initially empty, and we maintain who is the next member in the line. When iterating a value of bi, there are three cases:
If biis equal to the next member in the line, then we can make that member present. And then he/she will become a pending member for the next iterations.
Else, if bi is one of the pending members, then we can always set a precise target position when moving that member in the past such that he/she will be at the very front of the line at this very moment. And then, that member will be a pending member again.
Else, then it's impossible to make member bi present at this time.
To solve the problem with updates, let's observe some special properties of b if b is valid. Notice that once a member becomes a pending member, he/she will be a pending member forever. And a member x becomes a pending member during the first occurence of value x b. Since the order of members becoming pending must follow the order of the members in the line, that means the first occurence for each value x in b must be in chronological order from 1 to n. More formally, let's define first[x] as follows:

If the value x appears at least once in b, then first[x] is the smallest index i such that bi=x.
If the value x doesn't appear in b, then first[x]=m+1.
Then, for b to be valid, it must hold that first[1]≤first[2]≤…≤first[n].

To handle the updates, we must maintain the array first. In order to do that, for each value x from 1 to n, we maintain a set of indices for every occurence of x in b. The value of first is just the minimum value in the set, or m+1 if the set is empty. An update to an element in b corresponds to two updates among the sets, which corresponds to two updates in array first.

To maintain the status on whether array first is non-decreasing or not, we maintain a value c which represents the number of pairs of adjacent indices (x,x+1) (for all 1≤x≤n−1) such that first[x]≤first[x+1]. The array is non-decreasing if and only if c=n−1. For an update to an index x in first, we only need to check how pairs (x−1,x) and (x,x+1) affect the value of c.

Time complexity for each test case: O((n+m+q)log(n+m))
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, q, f = 0;
int a[N], b[N], pos[N], val[N];
set<int> s[N];
/**
 * Updates the value of `val[i]` and the count of inversions `f` based on the changes to the set `s[a[i]]`.
 * This function is used to maintain the state of the presentation order after updates to the `b` array.
 *
 * @param i - The index of the member whose presentation order needs to be updated.
 */
void upd(int i)
{
    if (i > 1)
        f -= val[i - 1] > val[i];
    if (i < n)
        f -= val[i] > val[i + 1];
    val[i] = *s[a[i]].begin();
    if (i > 1)
        f += val[i - 1] > val[i];
    if (i < n)
        f += val[i] > val[i + 1];
}
/**
 * Solves a problem related to adjusting the presentation order of members.
 *
 * The function reads in the number of members (n), the number of presentation orders (m), and the number of updates (q).
 * It then reads in the initial presentation order (a) and the desired presentation order (b).
 *
 * The function maintains a set of indices for each member, representing the indices where that member appears in the desired presentation order (b).
 * It also maintains an array `val` that stores the index of the first occurrence of each member in the desired presentation order.
 *
 * The function checks if the desired presentation order is possible by counting the number of inversions in the `val` array.
 * If the desired presentation order is possible, the function prints "YA", otherwise it prints "TIDAK".
 *
 * The function then processes the updates to the desired presentation order (b) and updates the `val` array and the count of inversions accordingly.
 * After each update, it prints "YA" if the updated presentation order is possible, or "TIDAK" otherwise.
 */
void solve()
{
    cin >> n >> m >> q;
    f = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        s[i].clear();
        s[i].insert(m + 1);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        s[b[i]].insert(i);
    }
    for (int i = 1; i <= n; i++)
        val[i] = *s[a[i]].begin();
    for (int i = 1; i < n; i++)
        f += val[i] > val[i + 1];
    cout << (f ? "TIDAK\n" : "YA\n");
    while (q--)
    {
        int i, v;
        cin >> i >> v;
        s[b[i]].erase(i);
        upd(pos[b[i]]);
        s[b[i] = v].insert(i);
        upd(pos[v]);
        cout << (f ? "TIDAK\n" : "YA\n");
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
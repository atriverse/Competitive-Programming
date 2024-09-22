/*
B. Robin Hood and the Major Oak
time limit per test1 second
memory limit per test256 megabytes
In Sherwood, the trees are our shelter, and we are all children of the forest.
The Major Oak in Sherwood is known for its majestic foliage, which provided shelter to Robin Hood and his band of merry men and women.

The Major Oak grows ii new leaves in the i-th year. It starts with 1 leaf in year 1.

Leaves last for k years on the tree. In other words, leaves grown in year i last between years i and i+k−1 inclusive.

Robin considers even numbers lucky. Help Robin determine whether the Major Oak will have an even number of leaves in year n.

Input
The first line of the input contains a single integer t (1≤t≤104) — the number of test cases.

Each test case consists of two integers n, k (1≤n≤109, 1≤k≤n) — the requested year and the number of years during which the leaves remain.
Output
For each test case, output one line, "YES" if in year n the Major Oak will have an even number of leaves and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
Input
5
1 1
2 1
2 2
3 2
4 4
Output
NO
YES
NO
NO
YES
Note
In the first test case, there is only 1 leaf.

In the second test case, k=1, so in the 2-nd year there will be 22=4 leaves.

In the third test case, k=2, so in the 2-nd year there will be 1+22=5 leaves.

In the fourth test case, k=2, so in the 3-rd year there will be 22+33=4+27=31 leaves.
*/

//Solution
/*
The key observation is that ii has the same even/odd parity as i. Therefore, the problem reduces to finding whether the sum of k consecutive integers ending in n is even. This can be done by finding the sum of n−k+1,n−k+2,...,n−1,n which is k∗(2n−k+1)/2, and checking its parity. Alternatively, one can count the number of odd numbers in those k consecutive integers.

Note: Originally, the number of leaves grown was to be im according to the fractal nature of life where m is set to some integer. Developers decided to replace m with i for simplicity, following Filikec's suggestion.
*/
#include <iostream>
using namespace std;

#define ll long long

/**
 * Determines whether the Major Oak will have an even number of leaves in the n-th year, given the leaf lifetime of k years.
 *
 * @param n The year for which to check the leaf count.
 * @param k The number of years that leaves remain on the tree.
 * @return `true` if the number of leaves in the n-th year is even, `false` otherwise.
 */
bool isEvenLeaves(ll n, ll k) {
    if (n < 1) return true;  // No leaves before year 1
    
    ll start_year =  n - k + 1;
    ll odd_count=(start_year%2==0)?k/2:(((k-1)/2)+1);
    return odd_count % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        // Solution 1 by counting odd numbers in the range
        cout << (isEvenLeaves(n, k) ? "YES\n" : "NO\n");

        //OR 
        // Solution 2 by calculating the sum of the range and checking its parity
        cout << (((n+1)*n/2 - (n-k)*(n-k+1)/2)%2?"NO":"YES") << '\n';
    }
    
    return 0;
}

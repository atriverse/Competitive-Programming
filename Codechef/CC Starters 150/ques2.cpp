/*
Find Multiset State
You are given an array A of length N, along with an integer K.
It is known that A is sorted in non-descending order, that is, A  ≤A i+   for every 1≤i<N.

Repeat the following three-step operation K times:

First, find min(A)=X and max(A)=Y, i.e. the minimum and maximum elements in the array Delete X and Y from A (if there exists multiple occurrences, delete only 1 Append X+Y to the back of A
Note that after this, the length of A will have decreased by 1.
For example, if A=[1,1,2,3], performing the operation once will result in A=[1,2,4], because we delete one occurrence of the maximum and minimum elements  3 and 1 respectively), and append their sum 3+1=4 to the array
Find the final array A after all K operations have been performed.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line contains N and K — the size of the array and the number of times we need to apply the operation The second line contains N space-separated integers A1 A2, ,…,AN  — the initial elements of the array.
Output Format
For each test case, output on a new line the final array after all K operations have been performed.

Constraints
1≤T≤10^4
1≤K<N≤10^5
1≤A≤10^4
Ai≤A(i+1)   for 1≤i<N
The sum of N over all test cases does not exceed 10^5.

Input
5
4 1
1 1 2 3
4 2
1 1 2 3
3 2
1 10 100
7 4
2 5 12 13 14 19 20
4 2
6 6 6 6

Output
1 2 4
2 5
111
14 19 52
6 18

Explanation:
Test case 2: We start off with A=[1,1,2,3] and need to perform the operation K=2 times
First, we find min(A)=1,max(A)=3, then remove one occurrences of each, and finally append 1+3=4 to A.
Now, A=[1,2,4]

For the second operation, we find min(A)=1,max(A)=3, then remove one occurrences of each, and finally append 1+4=5 to A Now, A=[2,5].
Thus, A=[2,5] is the state after 2 operations.
*/

/**
How it works:

    The program uses a loop to solve 't' puzzles one after another.
    For each puzzle, it creates a special list called a 'deque' (double-ended queue) and fills it with the 'n' input numbers.
    It then performs the special operation 'k' times:
        It takes the first number (smallest) and the last number (largest) from the list.
        It adds these two numbers together.
        It puts this sum at the end of the list.
    After doing this 'k' times, it shows the final list using a function called 'showdq'.
Important logic: The key part of this code is how it uses a deque to efficiently get both the smallest and largest numbers. Since the input list is already sorted, the smallest number is always at the front of the deque, and the largest is always at the back. This makes the operations very quick and easy to perform.

This program is solving a puzzle that involves repeatedly combining the extreme values in a list of numbers. It's a good example of how using the right data structure (in this case, a deque) can make solving certain problems much easier and more efficient.
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Prints the contents of the given deque to the console, with each element separated by a tab character.
 *
 * @param g The deque to be printed.
 */
void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
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
/*
Time Complexity Analysis:
The main loop runs 't' times, where 't' is the number of test cases.

For each test case:

    -> Reading 'n' and 'k' is O(1)
    -> Creating the deque and filling it with 'n' elements is O(n)
    -> The inner loop runs 'k' times, and each iteration performs constant time operations (pop_front, pop_back, push_back) on the deque, which is O(1)
    -> Showing the final deque (showdq function) takes O(n-k) time, as the size of the deque reduces by 1 in each of the 'k' operations
    -> Therefore, for each test case, the time complexity is O(n + k + (n-k)) = O(n + k).

The overall time complexity for all test cases is O(t * (n + k)), where:

    -> t is the number of test cases
    -> n is the initial size of the array
    -> k is the number of operations to perform
*/
/*
Ratio By 2
You have 2 positive integers X and Y.

In one operation, you can change the value of one of the integers by 1 or −1.

Find the minimum number of operations needed to ensure that either X≥(2⋅Y) or  Y≥(2⋅X), i.e. either X is at least twice as large as Y, or Y is at least twice as large as X.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases The first and only line of test case contains 2 space-separated integers X and Y.
Output Format
For each test case, output on a new line the minimum number of operations.

Constraints 1≤T≤81
2≤X,Y≤10
Sample 1:
Input
6
2 4
4 4
3 5
10 6
8 7
2 7

Output:
0
2
1
1
3
0

Explanation:
Test case 1: Y≥(2⋅X) already holds as 4≥(2⋅2).

Test case 2: Decrease Y twice by 1 to get X=4,Y=2. Then, X≥(2⋅Y) holds This is the minimum possible number of operations.

Test case
 3: Increase Y by 1 to get X=3,Y=6. Then Y≥(2⋅X) holds.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Solves the "Ratio By 2" problem from CodeChef.
 * Given two positive integers X and Y, finds the minimum number of operations needed to ensure that either X is at least twice as large as Y, or Y is at least twice as large as X.
 * An operation is defined as changing the value of one of the integers by 1 or -1.
 * The function reads the number of test cases T, and for each test case, reads the values of X and Y, and prints the minimum number of operations needed.
 */
int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		/*
		First, it checks if either 'b' is already at least twice as large as 'a', or if 'a' is already at least twice as large as 'b'. If either of these conditions is true, it means no operations are needed, so the code outputs 0.

		If neither number is twice as large as the other, the code calculates the minimum number of operations needed. It does this by finding the larger of the two numbers, dividing it by 2, and then subtracting the smaller number from this result. The absolute value of this difference is the number of operations needed.

		For example, if we have numbers 8 and 7, the larger number (8) divided by 2 is 4. The difference between 4 and the smaller number (7) is 3, which is the number of operations needed to make one number twice as large as the other.

		The logic here is that we're essentially calculating how many steps we need to take to reach the "halfway point" between the current situation and the desired ratio. This approach efficiently determines the minimum number of operations without actually performing them step-by-step.
		 */
		if (b >= 2 * a || a >= 2 * b)
		{
			cout << 0 << endl;
		}
		else
		{

			cout << abs(max(a, b) / 2 - min(a, b)) << endl;
		}
	}
}

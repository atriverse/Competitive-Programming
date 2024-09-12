/*
You are given a binary string S of length N.

For a positive integer k, you can perform the following operation on string S:

Choose k elements from the string S;
Perform a total of k flips on the chosen k elements. A flip changes a 0 to 1 and vice versa. Note that you can use multiple flips on the same element.
Find the count of all such k in range [1,N], such that, you can apply the operation optimally, and make all characters of the string equal.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases Each test case consists of multiple lines of input The first line of each test case contains an integer N — the length of the string S.
The next line contains a binary string S of length N.
Output Format
For each test case, output on a new line, the count of all such k in range [1,N], such that you can apply the operation optimally and make all characters of the string equal.

Constraints
1≤T≤2000
1≤N≤10^5
Si ∈{0,1}
The sum of 2N over all test cases won't exceed 2⋅10^5.
Sample 1:
Input
3
3
111
4
1001
5
00101

Output
2
2
4
Explanation:
Test case 1: Given S=111, let us consider all values of k in range [1,3] 
k=1: It is impossible to make all characters of the string same after applying a flip 
k=2: Choose S2 ,S3 , and perform two flips on S2  to obtain S=111 
k=3: Choose S1 ,S2  ,S3  and perform one flip each to obtain the string S=000 Thus, we can make all characters of the string same, using k=2 and k=3 
Test case 2: Given S=1001, let us consider all values of k in range [1,4] 
k=1: It is impossible to make all characters of the string same 
k=2: Choose S2  ,S3  , and perform one flip each on both to obtain S=1111 
k=3: It is impossible to make all characters of the string same 
k=4: Choose S1  ,S2  ,S3  ,S4  , and perform three flips on S2   and one flip on S3   to obtain S=1111 
Thus, we can make all characters of the string same, with k=2 and k=4.
*/


//Solution:
/*
The countValidK function takes a binary string (a string containing only '0's and '1's) as input and returns a count of how many ways the string can be made all the same (either all '0's or all '1's) by flipping a certain number of bits.

Here's how the function works:

    -> It counts how many '1's are in the string.
    -> It calculates how many '0's are in the string (total length minus number of '1's).
    -> It then checks for each possible number of flips (from 1 up to the length of the string) whether it's possible to make all characters the same using that many flips.
    -> It counts how many of these possible flip counts work.

The logic for determining if a certain number of flips (k) works is:

    -> If the number of flips is at least as large as the number of '1's, and the difference is even, it works (we can flip all '1's to '0's and use any extra flips in pairs).
    -> Or, if the number of flips is at least as large as the number of '0's, and the difference is even, it works (we can flip all '0's to '1's and use any extra flips in pairs).

The main function handles multiple test cases. For each test case, it:

    -> Reads the length of a binary string.
    -> Reads the binary string itself.
    -> Calls the countValidK function with this string.
    -> Prints the result.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Counts the number of valid values of k in the range [1, N] for which the given binary string S of length N can be made equal by performing k flips.
 *
 * @param S The binary string of length N.
 * @return The count of all valid values of k in the range [1, N] for which the string S can be made equal by performing k flips.
 */
int countValidK(const string& S) {
    int N = S.length();
    int ones = 0;
    for (char c : S) {
        if (c == '1') ones++;
    }
    int zeros = N - ones;
    
    int count = 0;
    for (int k = 1; k <= N; k++) {
        if ((ones <= k && (k - ones) % 2 == 0) || 
            (zeros <= k && (k - zeros) % 2 == 0)) {
            count++;
        }
    }
    
    return count;
}


int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        
        cout << countValidK(S) << endl;
    }
    
    return 0;
}

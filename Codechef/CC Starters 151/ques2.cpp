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
#include <bits/stdc++.h>
using namespace std;

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

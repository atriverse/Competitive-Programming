/*
Replacing Game
You are given two strings A and B, both of length N and containing only lowercase English letters 
You also have an integer K.

You can perform the following operation:

Choose a continuous substring of A of size exactly K, and a character c Then, replace all characters in the substring with c.
Formally, you choose an index i  (1≤i≤N−K+1) and a character c, and then set all of Ai,Ai+1,…,Ai+K−1 to c 
For example, if A=antear and K=2,

If we choose i=2 along with the character p, A will turn into appear.
If we instead i=5 and the character r, A will become anterr.
Check whether it's possible to make A equal to B through a series of such transformations. If it is possible, also output a list of transformations of size at most 2⋅N.

It can be proven that if it is possible to make A equal to B, it is also possible in 2⋅N transformations.
If multiple answers are possible, any of them will be accepted.

Note that you do not need to minimize the size of the list of transformations.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains N and K - the size of the strings and the size of the substrings to choose 
The second line of each test case contains A - a string of size N.
The third line of each test case contains B - a string of size N.
Output Format
For each test case:

If it is possible to transform A to B, first output M(0≤M≤2⋅N) - the number of transformations you would like to perform.
Then output M lines, each containing an integer i  1≤i≤N−K+1) and a character c, indicating that you want to change the substring S[i,i+K−1] to character c 
If it is impossible, output a single line containing the integer −1 instead If multiple solutions exist, you may print any of them Note that you do not have to minimize M, as long as M≤2N.

Constraint 
1≤T≤10^4 
2≤N≤2⋅10^5
2≤K≤N 
A and B both contain lowercase English letters only The sum of N over all test cases does not exceed 2⋅10^5   
Sample 1:
Input
4
3 2
abc
abc
3 2
abc
abd
4 4
opqk
cccc
4 2
abcd
ppqq
Output
0
-1
1
1 c
2
1 p
3 q
Explanation:
Test case 1: A=B already holds.

Test case 2: It can be proven that it's impossible to transform A into B.

Test case 3: Choose the substring A[1,4] of size exactly K=4 and replace with c to get A=cccc Now A=B.
*/

//Soultion:
/*
The code achieves its purpose through the following algorithm:

    It first checks if the input strings A and B are already equal. If so, it outputs 0 and moves to the next test case.

    If the strings are different, it searches for the longest continuous sequence of the same character in string B, starting from the end. This is done to find the most efficient way to make the transformations.

    If the length of the longest sequence (mx) is less than K, it's impossible to transform A into B, so it outputs -1.

    If transformation is possible, it constructs a list of transformations:

        It adds transformations for all characters before the longest sequence
        It adds transformations for all characters after the longest sequence + K
        Finally, it adds a transformation for the start of the longest sequence
    The program then outputs the number of transformations and the details of each transformation.

The main logic flow involves finding the longest sequence of the same character in B and using this to determine if and how the transformation can be done. The data transformation happens when constructing the list of transformations, where each transformation is represented as a pair of an index and a character.

This algorithm ensures that the transformation can be done in at most 2*N steps, as required by the problem statement. It's a clever solution that takes advantage of the problem constraints to provide an efficient answer.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
	// your code goes here
	int t; cin>>t; while(t--)
	{
	    int n, k; cin>>n>>k;
	    string s, t; cin>>s>>t;
	    
	    if(s == t)
	    {
	        cout<<0<<endl;
	        continue;
	    }
	    
	    int mx = 0;
	    int cnt = 1;
	    int idx = -1;
	    for(int i = n-2; i>=0; i--)
	    {
	        if(t[i] == t[i+1]) cnt++;
	        else 
	        {
	            if(cnt > mx)
	            {
	                mx = cnt;
	                idx = i + 1;
	            }
	            cnt = 1;
	        }
	    }
	    
	    if(cnt > mx)
	    {
	        mx = cnt;
	        idx = 0;
	    }
	    
	    if(mx<k)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    int idxk = idx + k;
	    
	    vector<pair<int,char>>ans;
	    
	    for(int i = 0; i<idx; i++) ans.push_back({i+1, t[i]});
	    for(int i = n-1; i>=idxk; i--) ans.push_back({i - k + 1 + 1, t[i]});
	    ans.push_back({idx + 1 , t[idx]});
	    cout<<ans.size()<<endl;
	    
	    for(auto it: ans) cout<<it.first<<" "<<it.second<<endl;
	    
	}

}
/*
Time Complexity:
The time complexity of this solution is O(N) for each test case, where N is the length of the input strings. This is because:

The initial comparison of strings s and t is O(N).
The loop to find the longest continuous sequence runs in O(N) time.
Constructing the list of transformations takes O(N) time in the worst case.
Outputting the transformations is also O(N) in the worst case.
Since the number of test cases is T, and the sum of N over all test cases doesn't exceed 2⋅10^5, the overall time complexity for all test cases combined is O(T * N), which is effectively O(2⋅10^5) in the worst case.
*/
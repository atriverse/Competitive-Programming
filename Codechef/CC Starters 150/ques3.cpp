/*
Equal Pairs (Easy)
This is the easy version of the problem. In this version, the array A is fixed from the start. The constraint on N is also smaller: 10 N≤100.

For an array A containing non-negative integers, we define f(A) as follows:

First, for each index i such that A  =0, replace A   by an arbitrary positive integer of your choice.
Then, calculate the number of pairs (i,j) such that i<j and Ai =Aj.
That is, the number of pairs of distinct indices that contain the same value.
Let this value be P.
f(A) is then the maximum possible value of P if you choose the replacements of the zeros appropriately 
You are given an array A, where some elements are 0 and the others are positive. Find f(A).

Input Format
The first line of input will contain a single integer T, denoting the number of test cases Each test case consists of two lines of input The first line of each test case contains N - the size of the array The second line contains N space-separated integers - A1  ,A2  ,…,AN  .
Output Format
For each test case, output on a new line the value of f(A).

Constraints
1≤T≤100
1≤N≤100
0≤Ai≤N
Sample 1:
Input
3
5
1 2 1 3 3
5
1 1 2 0 0
3
0 0 0
Output:
2
6
3

Explanation:
Test case 1: There are no 0-s to replace. The array A given is fixed, and we need to compute the number of equal pairs.

 (1,3) and (4,5) are the 2 pairs of indices with equal values.

Test case 
 2: We can replace both the 0-s with 1-s to get A=[1,1,2,1,1]. This has 6 equal pairs 
*/

//Solution Explanation:
/*
The program uses a vector 'arr' to store the input array and another vector 'hash' to count the frequency of each number. It iterates through the input array, updating the frequency count in 'hash'.

Next, it calculates the sum of pairs for non-zero elements. For each number from 1 to n, it adds the number of pairs that can be formed with that frequency using the formula: frequency * (frequency - 1) / 2. It also keeps track of the maximum frequency (max_el) among non-zero elements.

Finally, it calculates the contribution of zeros. It adds the number of pairs that can be formed by replacing all zeros with the number that has the maximum frequency. This is done using the formula: (hash[0] + max_el) * (hash[0] + max_el - 1) / 2 - max_el * (max_el - 1) / 2.

The total sum represents the maximum number of equal pairs possible, which is then printed as the output for each test case.

This approach efficiently solves the problem by using frequency counting and mathematical formulas to calculate the number of pairs, avoiding the need for explicit pair counting or array manipulation.
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            hash[arr[i]]+=1;
        }
        int max_el;
        max_el=INT_MIN;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=hash[i]*(hash[i]-1)/2;
            max_el=max(max_el,hash[i]);
        }
        sum+=(hash[0]+max_el)*(hash[0]+max_el-1)/2-max_el*(max_el-1)/2;
        
        cout<<sum<<endl;
    }
}
/*
Time Complexity:
The time complexity of this solution is O(N) for each test case, where N is the size of the input array. Here's a breakdown:

Reading the input array and updating the hash vector: O(N)
Finding the maximum element and calculating the sum for non-zero elements: O(N)
Final calculation for zero elements: O(1)
The overall time complexity for T test cases would be O(T * N).
*/
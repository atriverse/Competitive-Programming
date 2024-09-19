/*
Range Minimize
You are given an array A containing N integers You can delete at most two of its elements.

Find the minimum possible value of (max(A)−min(A)) (in other words, the range of A) after the deletions.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases Each test case consists of two lines of input The first line of each test case contains a single integer N — the length of the array The second line contains N space-separated integers A1  ,A2  ,…,AN-1  .
Output Format
For each test case, output on a new line the minimum possible value of max(A)−min(A) after at most two deletions.

Constraints
1≤T≤10^5
3≤N≤2⋅10^5
1≤Ai≤10^9
 
The sum of N over all test cases won't exceed 2⋅10^5 .
Sample 1:
Input
3
3
2 3 1
5
1 10000 10 100 1000
6
64 11 998 1005 843 945

Output
0
99
162
Explanation:
Test case 1: Delete 1 and 2 to make the array A=[3] max(A)−min(A)=0 which is the best we can do 
Test case 2: Delete A  =10000 and A  =1000 to obtain A=[1,10,100], for which max(A)−min(A)=99 
Test case 3: Delete A  =64 and A  =11 to obtain A=[998,1005,843,945], which has a range of 162.
*/

//Solution:
/*
For each test case, the program first reads the number of elements in the array (n) and then reads n integers into a vector. After reading the input, it sorts the vector in ascending order. This sorting step is crucial for the algorithm to work correctly.

The core logic of the program lies in the output statement. It calculates three possible ranges:

    -> The difference between the largest element and the third smallest element (v[n-1] - v[2]) ==>deleting first two smallest elements
    -> The difference between the third largest element and the smallest element (v[n-3] - v[0]) ==> deleting last two largest elements
    -> The difference between the second largest element and the second smallest element (v[n-2] - v[1]) ==> deleting first and last element

The program then outputs the minimum of these three ranges. This approach works because after deleting at most two elements, the new minimum could be either the original minimum, the second smallest, or the third smallest element. Similarly, the new maximum could be either the original maximum, the second largest, or the third largest element.

By considering these three cases, the program effectively covers all possible scenarios of deleting up to two elements to minimize the range. The use of the min() function ensures that the smallest of these ranges is selected and output.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the minimum possible value of the range (max(A) - min(A)) after deleting at most two elements from the given array.
 * 
 * This function reads in the number of test cases, then for each test case:
 * 1. Reads in the length of the array and the array elements.
 * 2. Sorts the array in ascending order.
 * 3. Calculates the minimum range by considering three cases:
 *    a. Deleting the first two smallest elements
 *    b. Deleting the last two largest elements
 *    c. Deleting the first and last elements
 * 4. Outputs the minimum of these three ranges.
 */
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        cout<<min(v[n-1]-v[2],min(v[n-3]-v[0],v[n-2]-v[1]))<<endl;
    }
}

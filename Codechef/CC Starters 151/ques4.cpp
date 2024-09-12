/*
Sequence Search
A sequence X is defined as:
X1 =0;
X2 =A;
X3=B;
Xi= Xi−1 + Xi−2 - Xi−3 for all i>3.
Given an integer K, find the Kth smallest element of sequence X.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases 
Each test case consists of three space-separated integers A, B, and K, as mentioned in the statement.
Output Format
For each test case, output on a new line, the Kth   smallest element in the sequence.

Constraints

1≤T≤10^5

1≤A,B,K≤10^9
 
Sample 1:
Input
3
18 13 2
50 30 7
61 41 6
Output
13
110
123
Explanation:
Test case 1: The sequence is 0,18,13,31,… where the second smallest element is 13.

Test case 2: The sequence is 0,50,30,80,60,110,90,140,120,… where the seventh smallest element is 110.
*/


//Solution:

/*
This code is designed to solve a problem related to a special sequence of numbers. The purpose is to find the Kth smallest element in this sequence, given certain input values.

The program takes input in the form of multiple test cases. For each test case, it reads three numbers: a, b, and k. These represent:

    a: The second element of the sequence
    b: The third element of the sequence
    k: The position of the element we want to find in the sorted sequence

The output for each test case is a single number, which is the Kth smallest element in the sequence.

The algorithm uses a binary search approach to efficiently find the answer. Here's how it works:

    -> If k is 1, it immediately outputs 0 (the first element of the sequence) and returns.
    -> It sets up a search range from 1 to 10^18 (a very large number).
    -> It then enters a loop that keeps narrowing down this range until it finds the answer.
    -> In each iteration, it calculates a midpoint and checks how many elements in the sequence are less than or equal to this midpoint.
    -> Based on this count, it either updates the answer and searches in the lower half of the range, or moves to the upper half.
The logic for counting elements involves some clever math. It uses two formulas:

    -> temp1: Counts elements that are multiples of b plus a
    -> temp2: Counts elements that are multiples of b
By combining these counts, it can quickly determine if the midpoint is too high or too low without generating the entire sequence.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/**
 * Solves a problem related to a sequence X, where X1 = 0, X2 = A, X3 = B, and Xi = Xi-1 + Xi-2 - Xi-3 for i > 3. Given A, B, and K, this function finds the Kth smallest element in the sequence X.
 *
 * @param a The value of A in the sequence X.
 * @param b The value of B in the sequence X.
 * @param k The value of K, representing the Kth smallest element to find.
 */
void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    if(k==1){
        cout<<0<<endl;
        return;
    }
    ll si=1,ei=1e18,ans=-1;
    k--;
    while(si<=ei){
        ll mid=si+(ei-si)/2;
        ll temp1=0;
        if(mid-a>=0){
            temp1=(mid-a)/b + 1;
        }
        ll temp2=mid/b;
        if(temp1+temp2>=k){
            ans=mid;
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    cout<<ans<<endl;
    
}

int main(){

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
} 

/*
Shooting (Easy)
This is the easy version of the problem. The only difference between this and hard version is the constraints on N — notably, in this version, N=1.

Aarsi and Krypto were competing in a shooting game.

You are given a matrix A of size N×M representing a shooting board. The cells of the matrix contain information about which player took a shot at which cell:

If A (i,j)  =0, no player took a shot at that cell.
If A (i,j) =1, Aarsi took a shot at that cell.
If A (i,j) =2, Krypto took a shot at that cell.
If A (i,j) =3, both players took a shot at that cell.
Let the bullseye cell be (x1  ,y1  ), then, for a shot at cell (x2  ,y2  ), the score of the shot is calculated as ma max(∣x1  −x2 ∣,∣y1  −y2  ∣). The score of a player is the sum of scores of all shots by that player.

Your task is to consider each cell in the matrix as the bullseye cell and find the value of ∣Aarsi's score - Krypto's scor ∣ accordingly.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases 
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers N and M — the number of rows and columns in the matrix, respectively 
The next N lines describe the matrix A. The ith   of these lines contain M space-separated integers ― the values A (i,1)  ,A (i,2)  ,…,A (i,M ) .
Output Format
For each test case, output a matrix B where B(i,j) denotes the value of ∣Aarsi's score - Krypto's scor ∣ considering (i,j) as the bullseye cell 
Constraints
1≤T≤10^4
N=1
1≤M≤3⋅10 ^5
0≤A(i,j) ≤3
The sum of N⋅M over all test cases won't exceed 3⋅10^5  .
Sample 1:
Input
2
1 5
2 1 3 0 1
1 8
1 1 3 0 2 0 3 3
Output
5 2 1 0 1
3 2 1 4 7 8 9 10


Explanation:
Test case 1: Aarsi took shot on cells (1,2),(1,3),(1,5) while Krypto took shot on cells (1,1),(1,3).

Considering (1,2) as the bullseye cell, Aarsi's score would be max(∣1−1∣,∣2−2∣)+max(∣1−1∣,∣2−3∣)+max(∣1−1∣,∣2−5∣)=4. Similarly, Krypto's score would be 2.

Thus, B (1,2)  =∣4−2∣=2 
*/

//Sollution:

/*
The input for each test case consists of two integers: n (always 1) and m (the number of columns), followed by m integers representing the shots taken in each cell of the grid. The values 0, 1, 2, and 3 represent no shot, Aarsi's shot, Krypto's shot, and both players' shots respectively.

The output is a series of m numbers, each representing the absolute difference between Aarsi's and Krypto's scores if the corresponding cell were the bullseye.

The code achieves its purpose through the following steps:

    -> It reads the input and stores the shot information in vector v.
    -> It creates two vectors, a and b, to keep a running count of Aarsi's and Krypto's shots respectively.
    -> It calculates initial sums (sum1 for Aarsi and sum2 for Krypto) based on the position of their shots.
    -> It then iterates through each possible bullseye position, calculating and outputting the score difference.

The key logic in this code is how it efficiently updates the scores as it moves the bullseye from left to right. Instead of recalculating everything for each bullseye position, it adjusts the previous scores by adding the shots at the current position and subtracting the shots that are now further away.

The main() function handles multiple test cases by reading the number of test cases t and calling the solve() function that many times.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/**
 * Solves a problem related to a shooting board matrix.
 * 
 * The function takes in the dimensions of the matrix and a vector representing the values in the matrix.
 * It then calculates the difference between Aarsi's score and Krypto's score for each cell in the matrix, considering that cell as the bullseye.
 * The scores are calculated based on the absolute difference between the row and column indices of the shot cell and the bullseye cell.
 * The function outputs the calculated differences for each cell in the matrix.
 * 
 * @param n The number of rows in the matrix.
 * @param m The number of columns in the matrix.
 * @param v A vector representing the values in the matrix.
 */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll>v(m);
    for(int i=0;i<m;i++)cin>>v[i];
    vector<int>a(m),b(m);
    a[0]=(v[0]==1 || v[0]==3);
    b[0]=(v[0]==2 || v[0]==3);;
    for(int i=1;i<m;i++){
        a[i]=a[i-1]+(v[i]==1 || v[i]==3);
        b[i]=b[i-1]+(v[i]==2 || v[i]==3);
    }
    ll sum1=0,sum2=0;
    for(int i=1;i<m;i++){
        if(v[i]==1 || v[i]==3){
            sum1+=i;
        }
        if(v[i]==2 || v[i]==3){
            sum2+=i;
        }
    }
    for(int i=0;i<m;i++){
        cout<<abs(sum1-sum2)<<" ";
        sum1+=a[i];
        sum2+=b[i];
        if(i==m-1)break;
        sum1-=(a[m-1]-a[i]);
        sum2-=(b[m-1]-b[i]);
    }
    cout<<endl;
    
}

int main(){
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
} 


/*
B. Three Brothers
time limit per test1 second
memory limit per test256 megabytes
Three brothers agreed to meet. Let's number the brothers as follows: the oldest brother is number 1, the middle brother is number 2, and the youngest brother is number 3.

When it was time for the meeting, one of the brothers was late. Given the numbers of the two brothers who arrived on time, you need to determine the number of the brother who was late.

Input
The first line of input contains two different integers a and b (1 ≤ a, b ≤ 3, a ≠ b) — the numbers of the brothers who arrived on time. The numbers are given in arbitrary order.

Output
Output a single integer — the number of the brother who was late to the meeting.

Example
InputCopy
3 1
OutputCopy
2

*/

#include<bits/stdc++.h> 

using namespace std;

/**
 * Determines the number of the brother who was late to the meeting based on the numbers of the two brothers who arrived on time.
 * 
 * @param a The number of one of the brothers who arrived on time.
 * @param b The number of the other brother who arrived on time.
 * @return The number of the brother who was late to the meeting.
 */
int f(int a,int b){
    if(a+b==3) return 3;
    else if(a+b==4) return 2;
    else return 1;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<f(a,b);
    return 0;
}
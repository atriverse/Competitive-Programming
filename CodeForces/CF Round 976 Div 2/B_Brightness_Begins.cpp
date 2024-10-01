/*
B. Brightness Begins
time limit per test1 second
memory limit per test256 megabytes
Imagine you have n light bulbs numbered 1,2,…,n. Initially, all bulbs are on. To flip the state of a bulb means to turn it off if it used to be on, and to turn it on otherwise.

Next, you do the following:

for each i=1,2,…,n, flip the state of all bulbs j such that j is divisible by i†.
After performing all operations, there will be several bulbs that are still on. Your goal is to make this number exactly k.

Find the smallest suitable n such that after performing the operations there will be exactly k bulbs on. We can show that an answer always exists.

† An integer x is divisible by y if there exists an integer z such that x=y⋅z.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The only line of each test case contains a single integer k (1≤k≤1018).

Output
For each test case, output n — the minimum number of bulbs.

Example
Input
3
1
3
8
Output
2
5
11
Note
In the first test case, the minimum number of bulbs is 2. Let's denote the state of all bulbs with an array, where 1 corresponds to a turned on bulb, and 0 corresponds to a turned off bulb. Initially, the array is [1,1].

After performing the operation with i=1, the array becomes [0–,0–].
After performing the operation with i=2, the array becomes [0,1–].
In the end, there are k=1 bulbs on. We can also show that the answer cannot be less than 2.

In the second test case, the minimum number of bulbs is 5. Initially, the array is [1,1,1,1,1].

After performing the operation with i=1, the array becomes [0–,0–,0–,0–,0–].
After performing the operation with i=2, the array becomes [0,1–,0,1–,0].
After performing the operation with i=3, the array becomes [0,1,1–,1,0].
After performing the operation with i=4, the array becomes [0,1,1,0–,0].
After performing the operation with i=5, the array becomes [0,1,1,0,1–].
In the end, there are k=3 bulbs on. We can also show that the answer cannot be smaller than 5.
*/


//Editiorial
/*
For any bulb i, its final state depends on the parity of the number of divisors of i. If i has an even number of divisors, then bulb i will be on; else it will be off. This translates to, if i is not a perfect square, bulb i will be on; else it will be off. So now the problem is to find the kth number which is not a perfect square. This can be done by binary searching the value of n such that n−⌊n−−√⌋=k or the direct formula n = ⌊k+k−−√+0.5⌋.
*/


//Code 1
#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the smallest suitable n such that after performing the operations there will be exactly k bulbs on.
 *
 * This function takes in the number of test cases t, and for each test case, it reads in the value of k (the number of bulbs that should be on) and then uses binary search to find the minimum value of n that satisfies this condition.
 *
 * @param t The number of test cases.
 * @param k The number of bulbs that should be on.
 * @return The minimum value of n that satisfies the condition.
 */
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         long long k, l = 1, r = 2e18;
//         cin >> k;
//         while(r-l > 1){
//             long long mid = (l+r)>>1;
//             long long n = mid - int(sqrtl(mid));
//             if(n >= k) r = mid;
//             else l = mid;
//         }
//         cout << r << "\n";
//     }
//     return 0;
// }

//Code 2

/**
 * Finds the minimum value of n such that there are exactly k bulbs on after performing the operations.
 *
 * This function reads in the number of test cases t, and for each test case, it reads in the value of k (the number of bulbs that should be on) and then calculates the minimum value of n that satisfies this condition using a simple formula.
 *
 * @param t The number of test cases.
 * @param k The number of bulbs that should be on.
 * @return The minimum value of n that satisfies the condition.
 */
int main(){
    int t;
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        cout << k + int(sqrtl(k) + 0.5) << "\n";
    }
    return 0;
}
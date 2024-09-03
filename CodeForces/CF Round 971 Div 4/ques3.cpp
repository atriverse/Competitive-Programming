#include <bits/stdc++.h>
using namespace std;

//Gives TLE with below code

// int minPath(int x, int y, int k) {
//     int steps = 0;
//     while (x > 0 || y > 0) {
//         if (steps % 2 == 0) {
//             // Moving in x direction
//             int move = min(x, k);
//             x -= move;
//         } else {
//             // Moving in y direction
//             int move = min(y, k);
//             y -= move;
//         }
//         steps++;
//     }
//     return steps;
// }

/**
 * Calculates the minimum number of jumps required for Freya to reach the target position (x, y) using jumps of size k.
 *
 * The function first calculates the ceiling of x/k and y/k, which represent the number of jumps required in the x and y directions respectively.
 * If the number of jumps required in the y direction is greater than or equal to the number of jumps required in the x direction, then the total number of jumps is 2 * the number of jumps required in the y direction.
 * Otherwise, the total number of jumps is 2 * the number of jumps required in the x direction minus 1.
 *
 * @param x The x-coordinate of the target position.
 * @param y The y-coordinate of the target position.
 * @param k The size of each jump.
 * @return The minimum number of jumps required for Freya to reach the target position.
 */
int minPath(int x, int y, int k) {
    //Ceiling of a/b = (a+b-1)/b
    int a=(x+k-1)/k; // Ceiling  of x/k
    int b=(y+k-1)/k; // Ceiling  of y/k
    return (a<=b)?2*b:2*a-1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << minPath(x, y, k) << endl;
    }
    return 0;
}

/*
Editorial:

Consider the x and y directions separately and calculate the jumps we need in each direction. The number of jumps we need in the x direction is ⌈x/k⌉ and similarily ⌈y/k⌉ in the y direction. Now let's try to combine them to obtain the total number of jumps. Let's consider the following cases:
⌈y/k⌉≥⌈x/k⌉. In this case, there will need to be ⌈y/k⌉−⌈x/k⌉ extra jumps in the y direction. While Freya performs these extra jumps, she will choose d=0 for the x direction. In total, there will need to be 2⋅⌈y/k⌉ jumps.

⌈x/k⌉>⌈y/k⌉. We can use the same reasoning as the previous case, but there's a catch. Since Freya is initially facing the x direction, for the last jump, she does not need to jump in the y direction. In total, there will need to be 2⋅⌈x/k⌉−1 jumps.
*/
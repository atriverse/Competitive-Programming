/*
Maximum Number of Moves to kill all pawns

There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.

Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:

The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.
In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.
Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.

Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.

Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

        \|/
    <--knight-->
        /|\


Example 1:

Input: kx = 1, ky = 1, positions = [[0,0]]

Output: 4

Explanation:

The knight takes 4 moves to reach the pawn at (0, 0).

Example 2:

Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]

Output: 8

Explanation:

Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).
Example 3:

Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]

Output: 3

Explanation:

Alice picks the pawn at (2, 4) and captures it in two moves: (0, 0) -> (1, 2) -> (2, 4). Note that the pawn at (1, 2) is not captured.
Bob picks the pawn at (1, 2) and captures it in one move: (2, 4) -> (1, 2).
 

Constraints:

0 <= kx, ky <= 49
1 <= positions.length <= 15
positions[i].length == 2
0 <= positions[i][0], positions[i][1] <= 49
All positions[i] are unique.
The input is generated such that positions[i] != [kx, ky] for all 0 <= i < positions.length.

*/


//Solution
/*
Approach
1. Precompute Distances Using BFS:
Use global static variable to ensure the flag is initialised once.

Use BFS to precompute and calculate the shortest distance from any point on the chessboard to all other points.
This gives us the distance matrix dist where dist[x1][y1][x2][y2] represents the shortest path from (x1, y1) to (x2, y2).

2. Recursive DP Function:
Define a recursive function f(curr, mask, turn) where curr is the index of the current pawn being considered, mask represents the set of captured pawns, and turn indicates whose turn it is (Alice or Bob).

If it’s Alice’s turn, maximize the score considering all possible moves.
If it’s Bob’s turn, minimize the score considering all possible moves.
*/
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int dist[50][50][50][50]; // 4D array to store distances between all pairs of points on the board
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // Possible moves in x-direction for a knight
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // Possible moves in y-direction for a knight

/**
 * Computes the shortest distances from the starting point (startx, starty) to all other points on the chessboard using a breadth-first search (BFS) algorithm.
 *
 * This function is used to precompute the distance matrix `dist`, which stores the shortest distance between any two points on the chessboard. The distance matrix is used in the main solution to efficiently compute the maximum/minimum score for the given positions.
 *
 * @param startx The starting x-coordinate.
 * @param starty The starting y-coordinate.
 */
// Function to compute shortest distances from (startx, starty) to all other points
void dis(int startx, int starty) {
    queue<pair<pair<int, int>, int>> q; // Queue to perform BFS: (current position, distance)
    q.push({{startx, starty}, 0});
    dist[startx][starty][startx][starty] = 0; // Distance from a point to itself is zero

    while(!q.empty()) {
        int x = q.front().first.first; // Current x-coordinate
        int y = q.front().first.second; // Current y-coordinate
        int d = q.front().second; // Distance from start point
        q.pop();

        for(int i = 0; i < 8; i++) {
            int newx = x + dx[i]; // New x-coordinate after move
            int newy = y + dy[i]; // New y-coordinate after move
            // Check if new position is within bounds and has not been visited yet
            if(newx >= 0 && newx < 50 && newy >= 0 && newy < 50 && dist[startx][starty][newx][newy] == -1) {
                dist[startx][starty][newx][newy] = 1 + d; // Update distance
                q.push({{newx, newy}, d + 1}); // Add new position to queue
            }
        }
    }
}

/**
 * Precomputes the shortest distances between all pairs of points on a 50x50 chessboard.
 * This function uses a breadth-first search (BFS) algorithm to compute the distance matrix `dist`,
 * which stores the shortest distance between any two points on the chessboard.
 * The distance matrix is used in the main solution to efficiently compute the maximum/minimum score for the given positions.
 * This function is called only once, and the computed distances are cached to avoid redundant computations.
 */
// Function to preprocess distances for all pairs of points
void pre() {
    static bool flag = false; // use of static bool to initialise the flag once
    if(flag) return; // Skip if already preprocessed
    memset(dist, -1, sizeof(dist)); // Initialize distances to -1
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            // Compute distances from (i, j) if not already computed
            if(dist[i][j][i][j] == -1) dis(i, j);
        }
    }
    flag = 1; // Mark preprocessing as done
}

class Solution {
public:
    vector<vector<int>> memo; // Memoization table for storing intermediate results

    /**
     * Recursively computes the maximum or minimum score for the knight's tour problem.
     * The function `f` takes the current position index, the visited positions mask, the current player's turn,
     * and the list of all positions. It returns the maximum or minimum score for the current player's turn.
     * The function uses memoization to avoid redundant computations.
     *
     * @param curr The index of the current position in the `positions` vector.
     * @param mask The bitmask representing the visited positions.
     * @param turn The current player's turn (0 for Alice, 1 for Bob).
     * @param positions The list of all positions on the chessboard.
     * @return The maximum or minimum score for the current player's turn.
     */
    // Recursive function to compute maximum/minimum score
    int f(int curr, int mask, int turn, vector<vector<int>>& positions) {
        int n = positions.size();
        if(mask == (1 << n) - 1) return 0; // All positions visited, base case

        // Check if result is already computed
        if(memo[curr][mask] != -1) return memo[curr][mask];

        int ans;
        int x = positions[curr][0]; // Current x-coordinate
        int y = positions[curr][1]; // Current y-coordinate

        if(!turn) { // Alice
            ans = INT_MIN; // Initialize to minimum value
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue; // Skip if position already visited
                int nextx = positions[i][0]; // Next x-coordinate
                int nexty = positions[i][1]; // Next y-coordinate
                int newDist = dist[x][y][nextx][nexty]; // Distance to next position
                // Compute maximum score by taking the maximum of all possible moves
                ans = max(ans, newDist + f(i, mask | (1 << i), !turn, positions));
            }
        } else { // Bob
            ans = INT_MAX; // Initialize to maximum value
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue; // Skip if position already visited
                int nextx = positions[i][0]; // Next x-coordinate
                int nexty = positions[i][1]; // Next y-coordinate
                int newDist = dist[x][y][nextx][nexty]; // Distance to next position
                // Compute minimum score by taking the minimum of all possible moves
                ans = min(ans, newDist + f(i, mask | (1 << i), !turn, positions));
            }
        }

        return memo[curr][mask] = ans;
    }


    /**
     * Computes the maximum number of moves a knight can make on a chessboard, starting from a given position and visiting a set of given positions.
     * The function uses a recursive approach with memoization to efficiently compute the maximum score.
     *
     * @param kx The x-coordinate of the knight's starting position.
     * @param ky The y-coordinate of the knight's starting position.
     * @param positions A vector of vectors representing the positions on the chessboard.
     * @return The maximum number of moves the knight can make.
     */
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky}); // Add knight's starting position to the list
        int n = positions.size(); // Total number of positions
        pre(); // Preprocess distances
        memo.resize(n, vector<int>(1 << n, -1)); // Initialize memoization table
        return f(n-1, (1<<(n-1)), 0, positions); // Start recursion with knight's position
    }
};

int main(){
    Solution s;
    vector<vector<int>> positions = {{1,1},{2,2},{3,3}};
    int x=0, y=2;
    cout << s.maxMoves(x, y, positions) << endl;
    return 0;
}
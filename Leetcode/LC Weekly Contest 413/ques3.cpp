/*
Select cells in grid with maximum score

You are given a 2D matrix grid consisting of positive integers.

You have to select one or more cells from the matrix such that the following conditions are satisfied:

No two selected cells are in the same row of the matrix.
The values in the set of selected cells are unique.
Your score will be the sum of the values of the selected cells.

Return the maximum score you can achieve.

Example 1:

Input: grid = [[1,2,*3],[*4,3,2],[*1,1,1]]

Output: 8

Explanation:

We can select the cells with values 1, 3, and 4 that are colored above.

Example 2:

Input: grid = [[8,7,6],[8,3,2]]

Output: 15

Explanation:

We can select the cells with values 7 and 8 that are colored above.

Constraints:

1 <= grid.length, grid[i].length <= 10
1 <= grid[i][j] <= 100

The algorithm uses a recursive approach with dynamic programming to solve the problem efficiently. Here's how it works:

    The maxScore function first converts the input grid into a vector of vectors called 'values'. Each inner vector contains the cell value, row, and column indices.
    
    It then sorts the 'values' vector in descending order based on the cell values. This sorting helps in considering higher-value cells first.
    
    The main logic is in the recur function, which uses recursion and memoization (storing results to avoid redundant calculations) to find the maximum score.
    
    The recur function takes the current index in the sorted 'values' vector, a bitmask representing selected rows, and a map for memoization.
    
    It checks if the current row has already been selected (using the bitmask). If so, it skips to the next cell. If not, it considers two options: selecting the current cell or skipping it.
    
    When selecting a cell, it adds its value to the score and marks the row as used in the bitmask. It then moves to the next unique value in the sorted list.
    
    The function compares the scores from selecting and not selecting the current cell, choosing the maximum.
    
    Results are stored in the dp map to avoid recalculating for the same state.

This approach efficiently explores all possible combinations of cell selections while adhering to the rules (no two cells from the same row, all selected values must be unique). By using memoization and considering cells in descending order of value, it optimizes the search for the maximum score.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recur(vector<vector<int>>& values, int idx, int mask_row, map<pair<int,int>, int>& dp)
    {
        int n= values.size();
        if(idx == n)
            return 0;
        
        if(dp.find({idx, mask_row})!= dp.end())
            return dp[{idx, mask_row}];
        
        int ans = 0;
        int row = values[idx][1];
        if((1<<row) & mask_row)
            ans += recur(values, idx+1, mask_row, dp);
        else
        {
            int j = idx;
            while (j< n and values[idx][0]== values[j][0])
                j++;
            
            int ans1= values[idx][0]+ recur(values, j, mask_row | (1<<row), dp);
            int ans2 = recur(values, idx+1, mask_row, dp);
            
            ans= max(ans1, ans2);
        }
            
        return dp[{idx, mask_row}]= ans;
        
    }
    int maxScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> values;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                values.push_back({grid[i][j], i, j});
            }
        }
        
        
        sort(values.begin(), values.end(), greater<vector<int>>());
        map<pair<int,int>, int> dp;
        
        return recur(values, 0, 0, dp);
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,3,2},{1,1,1}};
    Solution s;
    cout<<s.maxScore(grid);
    
    return 0;
}
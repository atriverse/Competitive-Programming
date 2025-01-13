#include <bits/stdc++.h>
using namespace std;
#define ll long long
class TrailSolver {
private:
    int n, m;
    string path;
    vector<vector<ll>> grid;
    vector<ll> row_sums;
    vector<ll> col_sums;
 
    void readInput() {
        cin >> n >> m;
        cin >> path;
        
        // Initialize vectors with proper sizes
        grid = vector<vector<ll>>(n + 1, vector<ll>(m + 1));
        row_sums = vector<ll>(n + 1, 0);
        col_sums = vector<ll>(m + 1, 0);
        
        // Read grid and calculate initial sums
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                row_sums[i] += grid[i][j];
                col_sums[j] += grid[i][j];
            }
        }
    }
 
    void processPath() {
        ll curr_row = 1, curr_col = 1;
        
        // Process each move in the path
        for(char move : path) {
            if(move == 'D') {
                ll temp = -row_sums[curr_row];
                grid[curr_row][curr_col] = temp;
                row_sums[curr_row] = temp + grid[curr_row][curr_col];
                col_sums[curr_col] += temp;
                curr_row++;
            } else {
                ll temp = -col_sums[curr_col];
                grid[curr_row][curr_col] = temp;
                col_sums[curr_col] = temp + grid[curr_row][curr_col];
                row_sums[curr_row] += temp;
                curr_col++;
            }
        }
        
        // Handle the final cell
        grid[n][m] = -col_sums[m];
    }
 
    void printResult() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
    }
 
public:
    void solve() {
        readInput();
        processPath();
        printResult();
    }
};
 
void solve() {
    TrailSolver solver;
    solver.solve();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n,vector(m,vector<int>(m,-1)));
        return f(grid, 0, 0, grid[0].size() - 1,dp);
    }

private:
    int f(vector<vector<int>>& grid, int i, int j1, int j2,vector<vector<vector<int>>> &dp) {
        int n = grid.size();
        int m = grid[0].size();

        // Out-of-bounds case
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;

        // Base case: last row
        if (i == n - 1) {
            if (j1 == j2) return dp[i][j1][j2] = grid[i][j1];
            else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        // Explore all paths Alice and Bob can take together
        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                value += f(grid, i + 1, j1 + dj1, j2 + dj2,dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create a DP table with dimensions [n][m][m]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base case: Fill the DP table for the last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Bottom-up calculation for all rows from n-2 to 0
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    // Explore all possible moves for both robots
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            } else {
                                value += -1e8; // Out-of-bounds condition
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // The answer is stored in dp[0][0][m-1] (both robots start at top corners)
        return dp[0][0][m - 1];
    }
};

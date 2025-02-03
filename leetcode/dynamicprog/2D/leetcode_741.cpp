#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n,vector(m,vector<int>(2,-1)));
        return f(grid,0,0,dp,0);
    }
    int f(vector<vector<int>>& grid, int i, int j,vector<vector<vector<int>>> &dp,int dirn) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (j < 0 || j >= m) return -1e8;
        if (i == n - 1 && j == n - 1 && dirn == 0) {
            return f(grid,0,0,dp,1);
        }
        if(i == 0 && j == 0 && dirn == 1){
            return dp[i][j][dirn];
        }
    }
};
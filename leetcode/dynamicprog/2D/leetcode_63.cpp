#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp (obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return f(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);
    }
    int f(vector<vector<int>> &obstacleGrid,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) {
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        int pathcount= f(obstacleGrid,i,j-1,dp) + f(obstacleGrid,i-1,j,dp);
        return dp[i][j]=pathcount;
    }
};
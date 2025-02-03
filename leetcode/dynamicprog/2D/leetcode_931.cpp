#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        for(int i = 0 ; i < matrix.size() ; i++){
            mini = min(mini,f(0,i,matrix));
        }
        return mini;
    }
    int f(int i , int j ,vector<vector<int>>& matrix){
        if(j < 0 || j > matrix[i].size() - 1) return INT_MAX;
        if(i == matrix.size()-1) return matrix[i][j];
        int dirn1 = f(i+1,j+1,matrix);
        int dirn2 = f(i+1,j,matrix);
        int dirn3 = f(i+1,j-1,matrix);

        int mini = matrix[i][j] + min(dirn1, min(dirn2, dirn3));

        return mini;
    }
};


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int m = matrix.size();
        int n = matrix.size();
        vector<vector<int>> dp (m,vector<int> (n,101));
        for(int i = 0 ; i < matrix.size() ; i++){
            mini = min(mini,f(0,i,matrix,dp));
        }
        return mini;
    }
    int f(int i , int j ,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(j < 0 || j > matrix[i].size() - 1) return INT_MAX;
        if(i == matrix.size()-1) return dp[i][j]=matrix[i][j];
        if(dp[i][j] != 101) return dp[i][j];
        int dirn1 = f(i+1,j+1,matrix,dp);
        int dirn2 = f(i+1,j,matrix,dp);
        int dirn3 = f(i+1,j-1,matrix,dp);

        int mini = matrix[i][j] + min(dirn1, min(dirn2, dirn3));

        return dp[i][j] = mini;
    }
};
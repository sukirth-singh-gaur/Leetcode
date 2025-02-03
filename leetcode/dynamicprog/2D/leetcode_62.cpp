#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
    int f(int i,int j){
        if(i==0 && j==0) {
            return 1;
        }
        if(i<0 || j<0) return 0;
        int pathcount= f(i,j-1) + f(i-1,j);
        return pathcount;
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<0 || j<0) return 0;
        int pathcount= f(i,j-1,dp) + f(i-1,j,dp);
        return dp[i][j] = pathcount;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m,vector<int>(n,-1));
        return f(m,n,dp);
    }
    int f(int m,int n,vector<vector<int>>&dp){
        // if(i==0 && j==0) {
        //     return 1;
        // }
        // if(dp[i][j]!=-1) return dp[i][j];
        // if(i<0 || j<0) return 0;
        // int pathcount= f(i,j-1,dp) + f(i-1,j,dp);
        // return dp[i][j] = pathcount;
        dp[0][0] = 1;
        for(int i  = 0 ; i < dp.size() ; i++){
            for(int j = 0 ; j < dp[i].size() ; j++){
                if(i == 0 && j == 0) continue;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
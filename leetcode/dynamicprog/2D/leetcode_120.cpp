#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(triangle, 0, 0);
    }
    int f(vector<vector<int>>& triangle, int i, int j) {
        if(i==triangle.size()-1) return triangle[i][j];
        int down = f(triangle, i + 1, j);
        int downRight = f(triangle, i + 1, j + 1);
        return triangle[i][j] + min(down, downRight);
    }
};




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp (m,vector<int> (n,-1));
        return f(triangle, 0, 0, dp);
    }
    int f(vector<vector<int>>& triangle, int i, int j,vector<vector<int>> &dp) {
        if(i==triangle.size()-1) return dp[i][j] = triangle[i][j];
        int down = f(triangle, i + 1, j,dp);
        int downRight = f(triangle, i + 1, j + 1,dp);
        return dp[i][j]=triangle[i][j] + min(down, downRight);
    }
};


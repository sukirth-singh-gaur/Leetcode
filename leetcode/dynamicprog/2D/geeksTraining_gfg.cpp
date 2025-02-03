#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
      return f(n-1,-1,arr);
    }
  private:
    int f(int day,int last,vector<vector<int>>&arr){
      if(day == 0){
      int maxi = 0;
        for(int i = 0; i < 3 ; i++){
          if(i!=last){
            maxi = max(maxi,arr[0][i]);
          }
        }
        return maxi;
      }
      int maxi = 0;
      int points = 0;
      for(int i = 0; i < 3 ; i++){
        if(i!=last){
          points = arr[day][i] + f(day - 1, i , arr);
          maxi = max(maxi,points);
        }
      }
      return maxi;
    }
};

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
      vector<vector<int>> dp(n,vector<int>(4,-1));
      return f(n-1,3,arr,dp);
    }
  private:
    int f(int day,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
      if(day == 0){
      int maxi = 0;
        for(int i = 0; i < 3 ; i++){
          if(i!=last){
            maxi = max(maxi,arr[0][i]);
          }
        }
        return maxi;
      }
      if(dp[day][last]!=-1) return dp[day][last];
      int maxi = 0;
      int points = 0;
      for(int i = 0; i < 3 ; i++){
        if(i!=last){
          points = arr[day][i] + f(day - 1, i , arr ,dp);
          maxi = max(maxi,points);
        }
      }
      return dp[day][last] = maxi;
    }
};

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
      vector<vector<int>> dp(n,vector<int>(4,-1));
      return f(n-1,3,arr,dp);
    }
  private:
    int f(int day,int next,vector<vector<int>>&arr,vector<vector<int>>&dp){
      dp[0][0] = max(arr[0][1],arr[0][2]);
      dp[0][1] = max(arr[0][0],arr[0][2]);
      dp[0][2] = max(arr[0][0],arr[0][1]);
      dp[0][3] = max(arr[0][1],max(arr[0][1],arr[0][2]));
      for(int day = 1 ; day < arr.size() ; day ++){
        for(int next = 0 ; next < 4 ;next ++){
          dp[day][next] = 0;
          for(int task = 0 ; task < 3 ; task ++){
            if(task != next){
              int points = arr[day][task] + dp[day-1][task];
              dp[day][next] = max(dp[day][next],points);
            }
          }
        }
      }
      return dp[arr.size()-1][3];
    }
};
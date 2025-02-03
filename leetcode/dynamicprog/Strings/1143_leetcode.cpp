#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size(),vector<int> (text2.size(),-1));
        return f(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
    int f(string text1, string text2,int ind1,int ind2,vector<vector<int>> & dp){
        //Base case
        if(ind1<0 || ind2<0) return 0;
        //Explore Possibilities 
        //Do comparisions characterwise
        //if match found decrease both the indexes by 1
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]){
            int match = 1 + f(text1,text2,ind1 - 1,ind2 -1,dp);
            return dp[ind1][ind2] = match;
        }
        //if they dont match move only one of the index in every way possible
        int moveind = 0 + max(f(text1,text2,ind1-1,ind2,dp),f(text1,text2,ind1,ind2-1,dp));
        return dp[ind1][ind2] = moveind;
    }
};     

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size()+1,vector<int> (text2.size()+1,0));
        return f(text1,text2,dp);
    }
    int f(string &text1, string &text2,vector<vector<int>> & dp){
        //Base Case
        for(int ind1 = 0; ind1<=text1.size(); ind1++){
            dp[ind1][0] =(text1[ind1]==text2[0]) ? 1 : (ind1 > 0)? dp[ind1-1][0] : 0;
        }
        for(int ind2 = 0; ind2<=text2.size(); ind2++){
            dp[0][ind2] =(text1[0]==text2[ind2]) ? 1 : (ind2 > 0)? dp[0][ind2-1] : 0;
        }
        //Explore possibilities
        for(int ind1 = 1 ; ind1 <= text1.size() ; ind1++){
            for(int ind2 = 1 ;ind2 <= text2.size() ; ind2++){
                if(text1[ind1-1] == text2[ind2-1]){
                    int match = 1 + dp[ind1 - 1][ind2 -1];
                    dp[ind1][ind2] = match;
                }else{
                    int moveind = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                    dp[ind1][ind2] = moveind;
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }   
};     
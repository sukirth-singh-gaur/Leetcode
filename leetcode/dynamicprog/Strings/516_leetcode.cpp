#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.size(),vector<int> (s.size(),-1));
        string sRev = s;
        reverse(sRev.begin(),sRev.end());
        return f(s,sRev,s.size()-1,s.size()-1,dp);
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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.size(),vector<int> (s.size(),-1));
        string sRev = s;
        reverse(sRev.begin(),sRev.end());
        return f(s,sRev,s.size()-1,s.size()-1,dp);
    }
    int f(string text1, string text2,int ind1,int ind2,vector<vector<int>> & dp){
    //Base case
    int n = text1.size();
    

}
};
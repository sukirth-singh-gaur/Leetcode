#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

void sums(vi arr,vi &ans, int n ,int i,int sum,vi& subarr){
    if(i==n){
        ans.push_back(sum);
        return;
    }
    // Include the current element
    subarr.push_back(arr[i]);
    sums(arr, ans, n, i + 1, sum + arr[i], subarr);
    subarr.pop_back();
    // Exclude the current element
    sums(arr, ans, n, i + 1, sum, subarr);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vi ans;
    vi subarr;
    sums(arr,ans,n,0,0,subarr);
    return ans;
}

int main(){

    return 0;
}
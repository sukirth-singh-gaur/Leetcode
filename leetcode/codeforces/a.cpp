#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
using namespace std;

void subsets(vector<int> arr,vector<int> &temp,vector<vector<int>> &subsetsArr,int index){
    if(index == arr.size()){
        return;
    }
    for(int i =  index ; i < arr.size() ; i++){
        temp.push_back(arr[i]);
        subsetsArr.push_back(temp);
        subsets(arr,temp,subsetsArr,i+1);
        temp.pop_back();
    }
}   

int sumSubarrayMins(vector<int>& arr){ 
    vector<int> temp;
    vector<vector<int>> subsetsArr;
    subsets(arr,temp,subsetsArr,0);
    vector<int> minimums(subsetsArr.size(),INT_MAX);
    int sum = 0;
    for(int i = 0 ; i < minimums.size() ; i++ ){
        for (int j = 0 ; j < subsetsArr[i].size(); j++){
            minimums[i] = min(minimums[i],subsetsArr[i][j]);
        }
        sum += minimums[i];
    }
    return sum;
}

int main(){
    vector<int> arr = {3,1,2,4};
    int ans =sumSubarrayMins(arr);
    cout<<ans<<endl;
    return 0;
} //heheheheeh shivi is babalumbabalumvore heheheheheh chotiiiiii gulu 
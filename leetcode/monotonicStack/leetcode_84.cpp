#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    vector<int> nextSmaller(heights.size(),heights.size());
    vector<int> prevSmaller(heights.size(),-1);
    stack<int> s;
    for(int i = 0; i < heights.size() ;i++){
        while(!s.empty()&&heights[s.top()]>= heights[i]){
            nextSmaller[s.top()] = i;
            s.pop();
        }
        if(!s.empty()){
            prevSmaller[i] = s.top();
        }
        s.push(i);
    }
    int maxArea = 0;
    for(int i = 0 ; i < heights.size() ;i++){
        int currHeight = heights[i];
        int area = currHeight * (nextSmaller[i] - prevSmaller[i] - 1);
        maxArea = max (area, maxArea);
    }
    return maxArea; 
}

int main(){
    vector<int> nums = {2,1,5,6,2,3};
    int ans = largestRectangleArea(nums);
    // for(int num : ans){
    //     cout<<num<<" ";
    // }
    cout<<ans;
    cout<<endl;
    return 0;   
}
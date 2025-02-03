#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(),0);
    stack<int> s;
    for(int i = 0; i < temperatures.size() ; i++){
        while(!s.empty()&&temperatures[s.top()]<temperatures[i]){
            ans[s.top()] =s.top() - 1 ;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main(){

    return 0;
}
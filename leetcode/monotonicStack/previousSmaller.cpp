#include <bits/stdc++.h>
using namespace std;

vector<int> findpreviousSmallerIndexes(vector<int> &arr){
    stack<int> s;
    vector<int> nextSmallerIndexes(arr.size(),-1);
    vector<int> previousSmallerIndexes(arr.size(),-1);
    for(int i = 0 ; i < arr.size() ; i++){
        while(!s.empty()&&arr[s.top()]>=arr[i]){
            nextSmallerIndexes[s.top()] = i ;
            s.pop();
        }
        if(!s.empty()) previousSmallerIndexes[i] = s.top() ;
        s.push(i);
    }
    return previousSmallerIndexes;
}

int main(){
    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
    vector<int> ans = findpreviousSmallerIndexes(arr);
    for(int index : ans){
        cout<< index <<" ";
    }
    return 0;
}
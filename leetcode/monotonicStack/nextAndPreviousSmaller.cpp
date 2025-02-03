#include <bits/stdc++.h>
using namespace std;

vector<int> findNextSmallerIndexes(vector<int> &arr){
    stack<int> s;
    vector<int> nextSmallerIndexes(arr.size(),-1);
    for(int i = 0 ; i < arr.size() ; i++){
        while(!s.empty()&&arr[s.top()]>=arr[i]){
            nextSmallerIndexes[s.top()] = i ;
            s.pop();
        }
        s.push(i);
    }
    return nextSmallerIndexes;
}

int main(){
    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
    vector<int> ans = findNextSmallerIndexes(arr);
    for(int index : ans){
        cout<< index <<" ";
    }
    return 0;
}
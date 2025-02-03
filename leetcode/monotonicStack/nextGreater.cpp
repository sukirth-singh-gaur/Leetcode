#include <bits/stdc++.h>
using namespace std;

vector<int> findNextGreaterIndexes(vector<int> & arr){
    // initialize an empty stack
    stack<int> s;
    // initialize nextGreater array, this array hold the output
    // initialize all the elements are -1 (invalid value)
    vector<int> nextGreater(arr.size(),-1);

    for(int i = 0 ; i < arr.size(); i++){
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is STRICTLY SMALLER than the current element
        // This means, the stack will always be monotonic non increasing 
        while(!s.empty() && arr[s.top()] < arr[i]){
            nextGreater[s.top()] = i;
            s.pop();
        }
        // push the current element
        s.push(i);
    }
    return nextGreater;
}

int main(){
    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
    vector<int> ans = findNextGreaterIndexes(arr);
    for(int index : ans){
        cout<< index <<" ";
    }
    cout<<endl;
}
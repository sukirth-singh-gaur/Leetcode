#include <bits/stdc++.h>
using namespace std;

vector<int> findPreviousGreaterIndexes(vector<int> & arr){
    // initialize an empty stack
    stack<int> s;
    // initialize nextGreater array, this array hold the output
    // initialize all the elements are -1 (invalid value)
    vector<int> previousGreater(arr.size(),-1);

    for(int i = 0 ; i < arr.size(); i++){
        // while loop runs until the stack is not empty AND
     // the element represented by stack top is SMALLER OR EQUAL to the current element
     // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
     // so equal elements will never stay in the stack (definition of strictly decreasing stack)
        while(!s.empty() && arr[s.top()] < arr[i]){
            s.pop();
        }
        // after the while loop, only the elements which are greater than the current element are left in stack
        // this means we can confidentally decide the previous greater element of the current element i, that's stack top
        if(!s.empty())
            previousGreater[i] = s.top();
        // push the current element
        s.push(i);
    }
    return previousGreater;
}

int main(){
    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
    vector<int> ans = findPreviousGreaterIndexes(arr);
    for(int index : ans){
        cout<< index <<" ";
    }
    cout<<endl;
}
#include<bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>&arr,int k){
    unordered_map<string,int> map;
    for(auto str:arr) map[str]++;
    for(auto str:arr){
        if(map[str]==1){
            k--;
        }
        if(k==0)
            return str;
    }
    return "";
}

int main(){
    vector<string>arr={"aaa","aa","a"};
    string ans=kthDistinct(arr,1);
    cout<<ans<<endl;
    return 0;
}
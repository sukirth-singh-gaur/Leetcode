#include<bits/stdc++.h>
using namespace std;

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.first>b.first;
}

string frequencySort(string s){
    int n=s.size();
    map<char,int> mpp;
    for(char c:s){
        mpp[c]++;
    }
    vector<pair<int,char>> v(mpp.size());
    int i =0;
    for(auto it : mpp){
        v[i].second=it.first;
        v[i].first=it.second;
        i++;
    }
    sort(v.begin(),v.end(),myComparison);
    s="";
    for(auto it: v){
        for(int i=0;i<it.first;i++){
            s+=it.second;
        }
    }
    return s;
}

int main(){
    string s ="tree";
    string ans = frequencySort(s);
    cout<<ans<<endl;
    return 0;
}
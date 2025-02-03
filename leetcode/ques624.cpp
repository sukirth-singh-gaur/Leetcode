#include<bits/stdc++.h>
using namespace std;

static bool comp1(const vector<int>& vec1, const vector<int>& vec2){
    if(vec1[0]==vec2[0]) return vec1.size()<vec2.size();
    return abs(vec1[0])<abs(vec2[0]);
}

static bool comp2(const vector<int>& vec1, const vector<int>& vec2){
    return abs(vec1[vec1.size()-1])<abs(vec2[vec2.size()-1]);
}

int maxDistance(vector<vector<int>>& arrays) {
    for(int i=0;i<arrays.size();i++){
        for(int j=0;j<arrays[i].size();j++){
            cout<<arrays[i][j]<<" ";
        }
        cout<<endl;
    }
    sort(arrays.begin(),arrays.end(),comp1);
    for(int i=0;i<arrays.size();i++){
        for(int j=0;j<arrays[i].size();j++){
            cout<<arrays[i][j]<<" ";
        }
        cout<<endl;
    }
    int smol = arrays[0][0];
    sort(arrays.begin()+1,arrays.end(),comp2);
    for(int i=0;i<arrays.size();i++){
        for(int j=0;j<arrays[i].size();j++){
            cout<<arrays[i][j]<<" ";
        }
        cout<<endl;
    }
    return abs(smol-arrays[arrays.size()-1][arrays[arrays.size()-1].size()-1]);
}

int main(){
    vector<vector<int>> arrays={{-2},{-3,-2,1}};
    int ans=maxDistance(arrays);
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
// int a = [] {
//     ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::ofstream out("user1.out");
//     std::cout.rdbuf(out.rdbuf());
//     return 0;
// }();
bool returnDist(vector<int> stalls,int noOfCows,int mid){
    int cowCount=1;//first cow ps
    int lastOccupied=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-lastOccupied>=mid){
            cowCount++;
            lastOccupied=stalls[i];
            if(cowCount==noOfCows) return true;
        }
    }
    return false;
}

void solve(){
    int ans=0;
    int noOfStalls,noOfCows;
    cin>>noOfStalls>>noOfCows;
    vector<int> stalls(noOfStalls);
    for(int i=0;i<noOfStalls;i++){
        cin>>stalls[i];
    }
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[noOfStalls-1]-stalls[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(returnDist(stalls,noOfCows,mid)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
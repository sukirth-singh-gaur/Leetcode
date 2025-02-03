#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
using namespace std;

    int minChanges(string s) {
        int minChangesRequired = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }
        return minChangesRequired;
    }


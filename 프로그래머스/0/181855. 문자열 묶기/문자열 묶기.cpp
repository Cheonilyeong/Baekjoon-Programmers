#include <bits/stdc++.h>

using namespace std;

int mx = INT_MIN;
map<int,int> mp;

int solution(vector<string> strArr) {
    for(string s : strArr) {
        mp[s.size()]++;
    }

    for(auto it : mp) {
        mx = max(mx, it.second);
    }
    return mx;
}
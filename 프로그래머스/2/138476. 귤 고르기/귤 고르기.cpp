#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int kind=0, num=0, cnt=0, pre=0;// 고른 종류, 고른 개수, 과일 수, 이전 과일
    vector<pair<int,int>> v;        // 개수, 종류
    
    sort(tangerine.begin(), tangerine.end());
    
    for(int t : tangerine) {
        if(pre!=0 && pre!=t) {
            v.push_back(make_pair(cnt,pre));
            cnt = 1;
            pre = t;
        }
        else {
            cnt++;
            pre = t;
        }
    }
    if(cnt > 0) v.push_back(make_pair(cnt,pre)); 
    
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    
    for(auto it : v) {
        kind++;
        num += it.first;
        if(num >= k) break;
    }
    
    return kind;
}
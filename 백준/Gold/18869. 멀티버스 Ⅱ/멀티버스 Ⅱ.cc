#include <bits/stdc++.h>
using namespace std;

int M, N, a, ret;
map<vector<int>,int> mp;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < M; i++) {

        vector<pair<int,int>> v;
        vector<int> v2(N);
        for(int j = 0; j < N; j++) {
            cin >> a;
            v.push_back({a,j});
        }

        sort(v.begin(), v.end());
        
        int pre = 0, n = 0;
        for(auto it : v) {
            if(it.first == pre) v2[it.second] = n;
            else {
                v2[it.second] = ++n;
                pre = it.first;
            }
        }

        mp[v2]++;
    }

    for(auto it : mp) {
        if(it.second >= 2) ret += (it.second * (it.second-1) / 2);
    }

    cout << ret;
}
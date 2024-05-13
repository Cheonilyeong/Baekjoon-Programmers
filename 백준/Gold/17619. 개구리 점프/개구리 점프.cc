#include <bits/stdc++.h>
using namespace std;

int N, Q, x1, x2, y, a, b;
vector<pair<int,int>> v;
vector<pair<int,int>> t;
map<int,pair<int,int>> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;

    // 통나무 받기 (i는 통나무 번호)
    for(int i = 1; i <= N; i++) {
        cin >> x1 >> x2 >> y;
        // 통나무 저장
        v.push_back({x1,x2});
        mp[i] = {x1,x2};
    }

    // 통나무 정렬하고 간추리기
    sort(v.begin(), v.end());
    int s = v[0].first, e = v[0].second;
    for(int i = 1; i < v.size(); i++) {
        auto it = v[i];
        if(it.first <= e) {
            e = max(e, it.second);
        }
        else {
            t.push_back({s,e});
            s = it.first;
            e = it.second;
        }
    }
    t.push_back({s,e});

    // Q
    while(Q--) {
        // 통나무 a->b (a<b)
        cin >> a >> b;
        if(a > b) swap(a,b);

        // a.x2 와 b.x1가 연결되어있어야함
        int s = mp[a].second;
        int e = mp[b].first;

        // 이분탐색
        bool flag = false;
        int l = 0, r = t.size()-1;
        while(l <= r) {
            int m = (l+r)/2;

            auto it = t[m];
            if(e < it.first) {
                r = m-1;
            }
            else if(s > it.second) {
                l = m+1;
            }
            // 겹치면
            else {
                if(s >= it.first && e <= it.second) flag = true;
                else flag = false;
                break;
            }
        }

        if(flag) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}
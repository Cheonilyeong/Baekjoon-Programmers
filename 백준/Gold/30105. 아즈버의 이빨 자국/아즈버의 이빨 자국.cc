#include <bits/stdc++.h>
using namespace std;

int N, cnt;
vector<int> v;
vector<int> ret;
set<int> teeth;
set<int> gap;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        teeth.insert(v[i]);
    }

    for(int i = 1; i < N; i++) {
        gap.insert(v[i]-v[0]);
    }

    for(int diff : gap) {
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(teeth.find(v[i]-diff) != teeth.end()) continue;
            if(teeth.find(v[i]+diff) != teeth.end()) continue;      
            flag = false;
            break;
        
        }
        if(flag) {
            cnt++;
            ret.push_back(diff);
        }
    }

    if(cnt >= 1) {
        cout << cnt << '\n';
        sort(ret.begin(), ret.end());
        for(int i : ret) cout << i << ' ';
    }
    else {
        cout << cnt;
    }
}
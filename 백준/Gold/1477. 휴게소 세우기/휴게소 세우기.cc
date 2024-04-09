#include <bits/stdc++.h>
using namespace std;

int N, M, L, ret=INT_MAX;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> L;

    v.resize(N);
    for(int i = 0; i < N; i++) {cin >> v[i];}
    v.push_back(0);
    v.push_back(L);

    sort(v.begin(), v.end());

    int l = 1, r = L;
    while(l <= r) {
        int m = (l + r) / 2;

        int cnt = 0;
        for(int i = 0; i < v.size()-1; i++) {
            int d = v[i+1] - v[i];
            
            cnt += (d / m);
            if(d % m == 0) cnt--;
        }

        if(cnt > M) {
            l = m+1;
        }
        else {
            ret = min(ret, m);
            r = m-1;
        }
    }

    cout << ret;
}
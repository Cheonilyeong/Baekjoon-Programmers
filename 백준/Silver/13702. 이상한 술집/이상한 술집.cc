#include <bits/stdc++.h>
using namespace std;

int N, K;
long long l=LLONG_MAX, r=LLONG_MIN, m, ret;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> K;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    l = 0; r = INT_MAX;
    while(l <= r) {

        m = (l + r) / 2;
        if(m == 0) break;

        int cnt = 0;
        for(int i : v) {
            cnt += (i/m);
        }

        if(cnt >= K) {
            ret = max(ret,m);
            l = m+1;
        }
        else r = m-1;
    }

    cout << ret;
}
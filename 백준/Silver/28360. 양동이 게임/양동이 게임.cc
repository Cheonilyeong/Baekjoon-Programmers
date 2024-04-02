#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
double cnt[54], ret=DBL_MIN;
vector<int> v[54];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[(int)a].push_back(b);
    }

    cnt[1] = 100;

    for(int i = 1; i <= N; i++) {
        if(cnt[i] == 0) continue;

        double div = cnt[i] / v[i].size();
        for(int j : v[i]) {
            cnt[j] += div;
            cnt[i] -= div;
        }
    }

    for(int i = 1; i <= N; i++) {
        ret = max(ret, cnt[i]);
    }

    cout << ret;
}   
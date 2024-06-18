#include <bits/stdc++.h>
using namespace std;

int n, m, r, a, b, l, ret, dist[104][104];
const int INF = 1e9 + 7;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> r;

    // 아이템
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 간선
    fill(dist[0], dist[0]+104*104, INF);
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        a--, b--;
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
    }

    // 플로이드 워셜
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 브루트포스
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(dist[i][j] <= m) sum += v[j];
        }
        ret = max(ret, sum);
    }

    cout << ret;
}
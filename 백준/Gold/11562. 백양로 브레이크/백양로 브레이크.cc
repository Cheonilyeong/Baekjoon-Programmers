#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, b, K, s, e, adj[255][255];
const int INF = 1e9+7;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    fill(&adj[0][0], &adj[254][254], INF);

    for(int i = 0; i < M; i++) {
        cin >> u >> v >> b;
        if(b) {
            adj[u][v] = 0;
            adj[v][u] = 0;
        }
        else {
            adj[u][v] = 0;
            adj[v][u] = 1;
        }
    }

    // 플로이드 워셜
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

            }
        }
    }

    cin >> K;
    while(K--) {
        cin >> s >> e;

        if(s == e) cout << 0 << '\n';
        else cout << adj[s][e] << '\n';
    }
}
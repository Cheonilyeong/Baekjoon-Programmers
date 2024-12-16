#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int TC, N, M, W, S, E, T;
int adj[504][504];
bool ret;

int main() {
    
    cin >> TC;

    while(TC--) {
        
        cin >> N >> M >> W;

        fill(&adj[0][0], &adj[0][0] + 504*504, INF);
        ret = false;

        for(int i = 0; i < 504; i++) {
            adj[i][i] = 0;
        }

        // M
        for(int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            
            if(adj[S][E] == INF || adj[S][E] > T) {
                adj[S][E] = T;
                adj[E][S] = T;
            }
        }

        // W
        for(int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            
            if(adj[S][E] == INF || adj[S][E] > -T) {
                adj[S][E] = -T;
            }
        }

        // 플로이드 워셜
        for(int m = 1; m <= N; m++) {
            for(int s = 1; s <= N; s++) {
                for(int e = 1; e <= N; e++) {
                    adj[s][e] = min(adj[s][e], adj[s][m] + adj[m][e]);
                }
            }
        }

        // 확인
        for(int i = 1; i <= N; i++) {
            if(adj[i][i] < 0) ret = true;
        }

        if(ret) cout << "YES\n"; else cout << "NO\n"; 
    }
}
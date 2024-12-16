#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

int TC, N, M, W, S, E, T;
long long adj1[504][504], dist[504];
bool ret;

int main() {
    
    cin >> TC;

    while(TC--) {
        
        cin >> N >> M >> W;

        fill(&adj1[0][0], &adj1[0][0] + 504 * 504, INF);
        memset(dist, 0, sizeof(dist));
        ret = false;

        // M
        for(int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            
            if(adj1[S][E] == INF || adj1[S][E] > T) {
                adj1[S][E] = T;
                adj1[E][S] = T;
            }
        }

        // W
        for(int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            
            if(adj1[S][E] == INF || adj1[S][E] > -T) {
                adj1[S][E] = -T;
            }
        }

        // d
        vector<vector<pair<int,int>>> adj2(N+1);
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(adj1[i][j] != INF) {
                    adj2[i].push_back({j, adj1[i][j]});
                }
            }
        }

        // 벨만 포드
        for(int i = 0; i < N; i++) {
            for(int here = 1; here <= N; here++) {
                for(auto it: adj2[here]) {
                    long long d = it.second;
                    int to = it.first;

                    if(dist[here] != INF && dist[here] + d < dist[to]) {
                        if(i == N-1) ret = true;
                        dist[to] = dist[here] + d;
                    }
                }
            }   
        }
        
        if(ret) cout << "YES\n"; else cout << "NO\n"; 
    }
}
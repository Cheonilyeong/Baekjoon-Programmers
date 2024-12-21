#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int N, M, from, to, w, adj[1004][1004];
long long dist[1004];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;

    fill(&adj[0][0], &adj[1003][1003], INF);
    fill(dist, dist + 1004, INF);
    
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> w;
        adj[from][to] = min(adj[from][to], w);
    }

    cin >> from >> to;

    queue<int> q;
    q.push(from);
    dist[from] = 0;

    while(q.size()) {
        int now = q.front(); q.pop();

        for(int i = 1; i <= N; i++) {
            if(adj[now][i] != INF && dist[i] > dist[now] + adj[now][i]) {
                dist[i] = dist[now] + adj[now][i];
                q.push(i);
            }
        }
    }

    cout << dist[to];
}
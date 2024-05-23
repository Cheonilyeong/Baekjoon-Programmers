#include <bits/stdc++.h>
using namespace std;

int N, M, X, Y, u, v;
bool visited[2][1004];
vector<int> adj[1004];
vector<int> ret;

void dfs(int now, int cnt) {
    //if(cnt == Y) return;

    for(int next : adj[now]) {
        if(visited[(cnt+1)%2][next]) continue;
        visited[(cnt+1)%2][next] = true;
        dfs(next, cnt+1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> N >> M >> X >> Y;

    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(X, 0);

    for(int i = 1; i <= N; i++) {
        if(visited[Y%2][i]) ret.push_back(i);
    }

    if(ret.empty()) cout << -1;
    else for(int i : ret) cout << i << ' ';
}
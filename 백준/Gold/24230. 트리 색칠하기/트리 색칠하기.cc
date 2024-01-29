#include <bits/stdc++.h>

using namespace std;

int N, u, v, color[200004], visited[200004], ret;
vector<int> adj[200004];

void go(int n) {
    if(adj[n].empty()) return;

    for(int i : adj[n]) {
        if(visited[i]) continue;
        if(color[n] != color[i]) ret++;
        visited[i] = 1;
        go(i);
    }
}
int main(void) {

    cin >> N;

    for(int i = 1; i<N+1; i++) {
        cin >> color[i];
    }

    for(int i = 0; i<N-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = 1;
    go(1);

    if(color[1] != 0) ret++;
    cout << ret;

}
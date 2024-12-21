#include <bits/stdc++.h>

using namespace std;

int n, s, v, w, visited[10004], from, mx = INT_MIN;
vector<pair<int,int>> adj[10004];

void dfs(int now, int sum) {
    if(sum > mx) {
        from = now;
        mx = sum;
    }

    visited[now] = 1;

    for(auto next: adj[now]) {
        if(visited[next.first]) continue;
        dfs(next.first, sum + next.second);
    }

    visited[now] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n-1; i++) {
        cin >> s >> v >> w;
        
        adj[s].push_back({v,w});
        adj[v].push_back({s,w});
    }

    dfs(1, 0);
    dfs(from, 0);

    cout << mx;
}  
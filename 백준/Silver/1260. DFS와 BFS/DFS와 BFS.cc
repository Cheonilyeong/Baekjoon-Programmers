#include <bits/stdc++.h>
using namespace std;

int N, M, V, a, b, visited[1004];
vector<int> v[1004];

void dfs(int num) {
    if(visited[num]) return;

    visited[num] = 1;
    cout << num << ' ';

    for(int i : v[num]) {
        dfs(i);
    }
}

void bfs(int num) {
    memset(visited,0,sizeof(visited));
    queue<int> q;

    visited[num] = 1;
    q.push(num);

    while(q.size()) {
        int now = q.front(); q.pop();
        
        cout << now << ' ';

        for(int next : v[now]) {
            if(visited[next]) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < 1004; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V); 
    cout << '\n';
    bfs(V);
}
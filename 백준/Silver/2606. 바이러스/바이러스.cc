#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, visited[104];
vector<int> v[104];

int dfs(int num) {

    int cnt = 1;

    for(int next : v[num]) {
        if(visited[next]) continue;
        visited[next] = 1;
        cnt += dfs(next);
    }

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[1] = 1;
    cout << dfs(1)-1;
}
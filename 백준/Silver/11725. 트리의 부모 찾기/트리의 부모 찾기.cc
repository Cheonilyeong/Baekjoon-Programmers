#include <bits/stdc++.h>
using namespace std;

int N, a, b, visited[100004], ret[100004];
vector<int> v[100004];

void dfs(int i) {
    visited[i] = 1;

    for(int next : v[i]) {
        if(visited[next]) continue;
        ret[next] = i;
        dfs(next);
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++) {
        cout << ret[i] << '\n';
    }
}
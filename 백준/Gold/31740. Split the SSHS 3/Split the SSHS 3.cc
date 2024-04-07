#include <bits/stdc++.h>
using namespace std;

int N, a, b, x, y;
vector<int> adj[100004];
int v[100004], visited[100004], total = 0;
int ret = INT_MAX, sum;
pair<int, int> retEdge;

int dfs(int pre, int num) {

    int cnt = v[num];

    for(int i : adj[num]) {
        if(visited[i]) continue;
        visited[i] = 1;
        cnt += dfs(num, i);
        visited[i] = 0;
    }

    if(sum-2*cnt >= 2*cnt-sum && ret > sum-2*cnt) ret=sum-2*cnt, x=pre, y=num;
    else if(sum-2*cnt < 2*cnt-sum && ret > 2*cnt-sum) ret=2*cnt-sum, x=pre, y=num;

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        cin >> a;
        v[i] = a;
        sum += a;
    }

    visited[1] = 1;
    dfs(0,1);

    cout << ret << '\n' << x << ' ' << y << '\n';
}
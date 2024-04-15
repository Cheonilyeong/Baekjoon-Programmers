#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, visited[104], cnt[104][104];
int mn=INT_MAX, ret=INT_MAX;
vector<int> v[104];

void bfs(int num) {
    queue<int> q;

    visited[num] = 1;
    q.push(num);

    while(q.size()) {
        int now = q.front(); q.pop();

        for(int next : v[now]) {
            if(visited[next]) continue;
            visited[next] = visited[now] + 1;
            cnt[num][next] = visited[next];
            q.push(next);
        }
    }

    memset(visited,0,sizeof(visited));
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    for(int i = 0; i < N; i++) {
        bfs(i);
    }

    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            sum += cnt[i][j]-1;
        }
        if(mn == sum) ret=min(ret,i);
        if(mn > sum) mn=sum, ret=i;
    }

    cout << ret+1;
}
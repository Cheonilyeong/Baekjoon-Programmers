#include <bits/stdc++.h>
using namespace std;

int N, M, y, x, visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[104][104];
queue<pair<int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    visited[0][0] = 1;
    q.push(make_pair(0,0));

    while(q.size()) {
        tie(y,x) = q.front(); q.pop();

        if(visited[N-1][M-1]) break;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(mp[ny][nx]=='0' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny,nx));
        }
    }

    cout << visited[N-1][M-1];
}
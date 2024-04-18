#include <bits/stdc++.h>
using namespace std;

int N, M, sy, sx, visited[604][604];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[604][604];

int dfs(int y, int x) {

    int cnt = 0;
    if(mp[y][x]=='P') cnt++;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(mp[ny][nx] == 'X' || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        cnt += dfs(ny,nx);
    }

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
            if(mp[i][j]=='I') sy=i, sx=j;
        }
    }

    int ret = dfs(sy,sx);
    if(ret) cout << ret;
    else cout << "TT";
}
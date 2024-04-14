#include <bits/stdc++.h>
using namespace std;

int T, M, N, K, y, x, ret, mp[2505][2505], visited[2505][2505];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(mp[ny][nx]==0 || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx);
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> M >> N >> K;

        while(K--) {
            cin >> x >> y;
            mp[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(mp[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    dfs(i,j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';

        memset(visited, 0, sizeof(visited));
        memset(mp, 0, sizeof(mp));
        ret = 0;
    }
}
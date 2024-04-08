#include <bits/stdc++.h>
using namespace std;

int R, C, y, x, visited[23][23], alpha[26], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[23][23];

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(visited[ny][nx] || alpha[mp[ny][nx]-'A']) continue;
        visited[ny][nx] = 1;
        alpha[mp[ny][nx]-'A'] = 1;
        dfs(ny,nx,cnt+1);
        visited[ny][nx] = 0;
        alpha[mp[ny][nx]-'A'] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> mp[i][j];
        }
    }

    alpha[mp[0][0]-'A'] = 1;
    visited[0][0] = 1;
    dfs(0,0,1);

    cout << ret;
}
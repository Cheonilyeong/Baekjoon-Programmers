#include <bits/stdc++.h>
using namespace std;

int T, N, visited[104][104], mode;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[104][104];
pair<int,int> ret;

void dfs(int y, int x, char color) {

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
        if(visited[ny][nx]) continue;
        if(mode) {
            if((color=='R' || color=='G') && (mp[ny][nx]=='R' || mp[ny][nx]=='G')) {
                visited[ny][nx] = 1;
                dfs(ny,nx,color);
            }
            if(color=='B' && mp[ny][nx]=='B') {
                visited[ny][nx] = 1;
                dfs(ny,nx,color);
            }
        }
        else {
            if(mp[ny][nx]==color) {
                visited[ny][nx] = 1;
                dfs(ny,nx,color);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            dfs(i,j,mp[i][j]);
            ret.first++;
        }
    }

    memset(visited, 0, sizeof(visited));
    mode = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            dfs(i,j,mp[i][j]);
            ret.second++;
        }
    }

    cout << ret.first << ' ' << ret.second;
}
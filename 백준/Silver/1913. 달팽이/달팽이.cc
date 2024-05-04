#include <bits/stdc++.h>
using namespace std;

int N, K, mode, visited[1000][1000];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int retY, retX;

void dfs(int y, int x, int mode) {
    if(y == N/2 && x == N/2) return;
    //cout << "visited " << y << ' ' << x << '\n';

    while(1) {
        int ny = y + dy[mode];
        int nx = x + dx[mode];

        if(ny<0 || ny>=N || nx<0 || nx>=N || visited[ny][nx]) {
            mode = (mode+1) % 4;
            continue;
        }
        
        visited[ny][nx] = visited[y][x] - 1;
        dfs(ny,nx,mode);

        break;
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> K;

    visited[0][0] = N*N;
    dfs(0,0,0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]==K) retY = i, retX = j;
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << retY+1 << ' ' << retX+1;
}
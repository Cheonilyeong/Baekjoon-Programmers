#include <bits/stdc++.h>
using namespace std;

int N, M, visited[1004][1004], ret;
char mp[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char dir[] = {'U', 'R', 'D', 'L'};

void dfs(int y, int x) {

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(visited[ny][nx]) continue;
        
        // (y,x) -> (ny,nx)
        // (y,x)에서 진행방향으로 (ny,nx)로 도착하는 경우
        if(mp[y][x]==dir[i]) {
            visited[ny][nx] = 1;
            dfs(ny,nx);
        }
        // (ny,nx) -> (y,x)
        // (ny,nx)에서 진행방향으로 (y,x)로 도착하는 경우
        else if(mp[ny][nx]==dir[(i+2)%4]) {
            visited[ny][nx] = 1;
            dfs(ny,nx);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 지도 받기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }
		// 그래프 탐색
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j]) continue;
            // 하나의 집합을 방문처리하고 ret++
            visited[i][j] = 1, ret++;
            dfs(i,j);
        }
    }

    cout << ret;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, visited[1004][1004][2];
char mp[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<tuple<int,int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    q.push({0,0,0});
    visited[0][0][0] = 1;

    while(!q.empty()) {
        int x, y, z;
        auto it = q.front(); q.pop();

        y = get<0>(it); x = get<1>(it); z = get<2>(it);

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            
            if(z) {
                if(mp[ny][nx]=='1' || visited[ny][nx][z] || visited[ny][nx][z-1]) continue;
                visited[ny][nx][z] = visited[y][x][z] + 1;
                q.push({ny,nx,z});
            }
            else {
                if(mp[ny][nx]=='1' && !visited[ny][nx][z+1]) {
                    visited[ny][nx][z+1] = visited[y][x][z] + 1;
                    q.push({ny,nx,z+1});
                }
                else if(mp[ny][nx]=='0' && !visited[ny][nx][z]) {
                    visited[ny][nx][z] = visited[y][x][z] + 1;
                    q.push({ny,nx,z});
                }
            }
        }
    }
    
    if(visited[N-1][M-1][0] || visited[N-1][M-1][1]) {
        if(visited[N-1][M-1][0] && visited[N-1][M-1][1]) 
            cout << min(visited[N-1][M-1][0],visited[N-1][M-1][1]);
        else 
            cout << max(visited[N-1][M-1][0],visited[N-1][M-1][1]);            
    }
    else cout << -1;
}
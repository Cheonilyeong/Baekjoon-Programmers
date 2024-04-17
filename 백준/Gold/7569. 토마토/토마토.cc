#include <bits/stdc++.h>
using namespace std;

int M, N, H, y, x, z, day, cnt;
int mp[103][103][103], visited[103][103][103];
int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<tuple<int,int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> mp[j][k][i];
                if(mp[j][k][i] == 1) {
                    visited[j][k][i] = 1;
                    q.push(make_tuple(j,k,i));
                }
                if(mp[j][k][i] == 0) cnt++;
            }
        }
    }

    if(cnt == 0) {
        cout << 0;
        exit(0);
    }

    while(q.size()) {
        auto it = q.front(); q.pop();
        y = get<0>(it); 
        x = get<1>(it); 
        z = get<2>(it);
        day = max(day,visited[y][x][z]);

        for(int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H) continue;
            if(mp[ny][nx][nz] == 1 || mp[ny][nx][nz] == -1 || visited[ny][nx][nz]) continue;
            visited[ny][nx][nz] = visited[y][x][z] + 1;
            q.push(make_tuple(ny,nx,nz));
            cnt--;
        }
    }

    if(cnt == 0) cout << day-1;
    else cout << -1;
}
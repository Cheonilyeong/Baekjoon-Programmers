#include <bits/stdc++.h>

using namespace std;

int visited[10][10];
int y, x;
int ny, nx, cnt;
queue<pair<int,int>> q;

int dy[8][3] = {
    {-1, -2, -3},
    {-1, -2, -3},
    {1, 2, 3},
    {1, 2, 3},
    {0, -1, -2},
    {0, 1, 2},
    {0, -1, -2},
    {0, 1, 2}
};

int dx[8][3] = {
    {0, -1, -2},
    {0, 1, 2},
    {0, -1, -2},
    {0, 1, 2},
    {-1, -2, -3},
    {-1, -2, -3},
    {1, 2, 3},
    {1, 2, 3}
};

int main() {

    cin >> y >> x;

    visited[y][x] = 1;
    q.push(pair(y,x));

    cin >> y >> x;

    while(q.size()) {
        auto now = q.front(); q.pop();

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 3; j++) {
                ny = now.first + dy[i][j];
                nx = now.second + dx[i][j];

                if(ny < 0 || ny > 9 || nx < 0 || nx > 8) break;
                
                if(j == 2) {
                    if(visited[ny][nx] == 0) {
                        q.push(pair(ny,nx));
                        visited[ny][nx] = visited[now.first][now.second]+1;
                    }
                } else {
                    if(y == ny && x == nx) break;
                }
            }
        }
    }

    if(visited[y][x] == 0) cout << -1; else cout << visited[y][x]-1;
}
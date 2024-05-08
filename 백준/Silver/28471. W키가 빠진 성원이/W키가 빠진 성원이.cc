#include <bits/stdc++.h>
using namespace std;

int N, FY, FX, y, x, cnt, visited[2004][2004];
char mp[2004][2004];
int dy[] = {-1, 0, 0, 1, 1, -1, -1};
int dx[] = {0, 1, -1, 1, -1, 1, -1};
queue<pair<int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'F') tie(FY,FX)={i,j}; 
        }
    }

    visited[FY][FX] = 1;
    q.push({FY,FX});

    while(q.size()) {
        tie(y,x) = q.front(); q.pop();

        for(int i = 0; i < 7; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            if(visited[ny][nx] || mp[ny][nx]=='#') continue;
            visited[ny][nx] = visited[ny][nx]+1;
            q.push({ny,nx});
            cnt++;
        }
    }

    cout << cnt;
}
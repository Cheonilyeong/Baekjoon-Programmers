#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, endX, endY, mp[1004][1004], visited[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void BFS(int y, int x) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});

    while(q.size()) {
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(mp[ny][nx] == 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}
int main(void) {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 2) tie(endY, endX) = {i, j};
        }
    }

    BFS(endY, endX);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mp[i][j] == 0) cout << 0 << ' ';
            else if(mp[i][j] != 0 && visited[i][j] == 0) cout << -1 << ' ';
            else cout << max(0, visited[i][j]-1) << ' ';
        }
        cout << '\n';
    }

}
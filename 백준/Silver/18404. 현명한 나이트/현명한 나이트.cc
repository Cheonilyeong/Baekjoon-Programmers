#include <bits/stdc++.h>
using namespace std;

int N, M, X, Y, visited[504][504];
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> X >> Y;

    visited[Y-1][X-1] = 1;
    queue<pair<int,int>> q;
    q.push({Y-1,X-1});
    while(q.size()) {
        auto it = q.front(); q.pop();
        
        for(int i = 0; i < 8; i++) {
            int ny = it.first + dy[i];
            int nx = it.second + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[it.first][it.second] + 1;
            q.push({ny,nx});
        }
    }

    while(M--) {
        cin >> X >> Y;
        cout << visited[Y-1][X-1]-1 << ' ';
    }
}
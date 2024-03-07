#include <bits/stdc++.h>
using namespace std;

int N, M, PR, PC, visited[504][504][4];
char mp[504][504];
vector<pair<int,char>> ret;

const char DIRECT[] = {'U', 'R', 'D', 'L'};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

const int INF = 1e9 + 7;

int dfs(int y, int x, int type) {

    visited[y][x][type] = 1;

    int cnt = 1;

    int ny = y + dy[type];
    int nx = x + dx[type];

    if(ny < 0 || ny >= N || nx < 0 || nx >= M) return cnt;
    if(mp[ny][nx] == 'C') return cnt;
    if(visited[ny][nx][type]) return INF;

    if(mp[ny][nx] == '\\') {
        if(type == 0) cnt += dfs(ny, nx, 3);
        if(type == 1) cnt += dfs(ny, nx, 2);
        if(type == 2) cnt += dfs(ny, nx, 1);
        if(type == 3) cnt += dfs(ny, nx, 0);
    }
    if(mp[ny][nx] == '/') {
        if(type == 0) cnt += dfs(ny, nx, 1);
        if(type == 1) cnt += dfs(ny, nx, 0);
        if(type == 2) cnt += dfs(ny, nx, 3);
        if(type == 3) cnt += dfs(ny, nx, 2);
    }
    if(mp[ny][nx] == '.') {
        cnt += dfs(ny, nx, type);
    }

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    cin >> PR >> PC;
    for(int i = 0; i < 4; i++) {
        ret.push_back({dfs(PR-1, PC-1, i), DIRECT[i]});
        memset(visited, 0, sizeof(visited));
    }

    sort(ret.begin(), ret.end());

    if(ret[3].first >= INF) cout << ret[3].second << '\n' << "Voyager";
    else cout << ret[3].second << '\n' << ret[3].first;
}
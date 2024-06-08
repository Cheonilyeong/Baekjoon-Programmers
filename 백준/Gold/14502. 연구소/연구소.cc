#include <bits/stdc++.h>
using namespace std;

int N, M, mp[10][10], visited[10][10], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int,int>> v;
vector<pair<int,int>> virus;

void dfs(int y, int x) {

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(mp[ny][nx] != 0 || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 연구소 맵 받기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 0) v.push_back({i,j});
            if(mp[i][j] == 2) virus.push_back({i,j});
        }
    }

    // 브루트포스
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            for(int k = j+1; k < v.size(); k++) {
                mp[v[i].first][v[i].second] = 1;
                mp[v[j].first][v[j].second] = 1;
                mp[v[k].first][v[k].second] = 1;

                memset(visited, 0, sizeof(visited));

                // 바이러스 확산
                for(auto it : virus) {
                    visited[it.first][it.second] = 1;
                    dfs(it.first, it.second);
                }
                // 안전구역
                int sum = 0;
                for(int y = 0; y < N; y++) {
                    for(int x = 0; x < M; x++) {
                        if(mp[y][x] == 0 && visited[y][x] == 0) sum++;
                    }
                }
                ret = max(ret, sum);

                mp[v[i].first][v[i].second] = 0;
                mp[v[j].first][v[j].second] = 0;
                mp[v[k].first][v[k].second] = 0;
            }
        }
    }

    cout << ret;
}
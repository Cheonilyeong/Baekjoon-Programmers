#include <bits/stdc++.h>
using namespace std;

int N, M, y, x, visited[2004][2004], root[2004][2004];
int startX, startY, endX, endY;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string s;
char mp[2004][2004];
vector<pair<int,int>> v;
queue<pair<int,int>> q;
map<pair<int,int>,pair<int,int>> parent;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < M; j++) {
            mp[i][j] = s[j];
            if((i == 0 || i == N-1 || j == 0 || j == M-1) && s[j] == '.') v.push_back({i,j});
        }
    }

    tie(startY, startX) = v[0];
    tie(endY, endX) = v[1];

    q.push({startY,startX});
    visited[startY][startX] = 1;

    while(q.size()) {
        tie(y,x) = q.front();
        q.pop();

        if(y == endY && x == endX) break;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(mp[ny][nx] == '+' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    while(y != startY || x != startX) {
        root[y][x] = 1;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(mp[ny][nx] == '.' && visited[ny][nx] == visited[y][x]-1) {
                tie(y,x) = {ny,nx};
                break;
            }
        }
    }
    root[y][x] = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mp[i][j] == '.' && root[i][j] == 0) cout << '@';
            else cout << mp[i][j];
        }
        cout << '\n';
    }
}
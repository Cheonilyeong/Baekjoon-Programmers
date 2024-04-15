#include <bits/stdc++.h>
using namespace std;

int N, visited[30][30];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[30][30];
vector<int> ret;

int dfs(int y, int x) {

    int cnt = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
        if(visited[ny][nx]) continue;
        if(mp[ny][nx]=='0') continue;
        visited[ny][nx] = 1;
        cnt += dfs(ny,nx);
    }

    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] || mp[i][j]=='0') continue;
            visited[i][j] = 1;
            ret.push_back(dfs(i,j));
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for(int i : ret) {
        cout << i << '\n';
    }
}
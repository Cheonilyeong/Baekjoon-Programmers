#include <bits/stdc++.h>
using namespace std;
#define y1 y3

int M, N, K, mp[104][104], visited[104][104];
int x1, y1, x2, y2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;

int dfs(int y, int x) {

    int cnt = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(mp[ny][nx] == 1 || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        cnt += dfs(ny, nx);
    }

    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> K;

    while(K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                mp[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(mp[i][j] == 0 && visited[i][j] == 0) {
                visited[i][j] = 1;
                ret.push_back(dfs(i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for(int i : ret) cout << i << ' ';
}
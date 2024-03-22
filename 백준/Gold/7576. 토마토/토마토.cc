#include <bits/stdc++.h>
using namespace std;

int M, N, y, x, day, cnt;
int mp[1004][1004], visited[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

void swapQ(queue<pair<int,int>>& q1, queue<pair<int,int>>& q2) {
    while(q2.size()) {
        tie(y,x) = q2.front();
        q2.pop();
        q1.push({y,x});
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 1) {
                visited[i][j] = 1;
                q1.push({i,j});
            }
            if(mp[i][j] == 0) cnt++;
        }
    }

    if(cnt == 0) {
        cout << 0;
        exit(0);
    }

    while(q1.size()) {
        day++;

        while(q1.size()) {
            tie(y,x) = q1.front();
            q1.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(mp[ny][nx] == 1 || mp[ny][nx] == -1 || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q2.push({ny,nx});
                cnt--;
            }
        }

        swapQ(q1,q2);
    }

    if(cnt == 0) cout << day-1;
    else cout << -1;
}
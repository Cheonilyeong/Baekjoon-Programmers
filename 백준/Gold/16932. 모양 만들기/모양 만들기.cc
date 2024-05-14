#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, visited[1004][1004], mp[1004][1004], ret=INT_MIN;
map<int,int> mp2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x) {
    
    int sum = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(visited[ny][nx] || mp[ny][nx]==0) continue;
        visited[ny][nx] = visited[y][x];
        sum += dfs(ny,nx);
    }

    return sum;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 배열 받기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    // 각 묶음 개수 세기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mp[i][j] && visited[i][j]==0) {
                visited[i][j] = ++cnt;
                mp2[cnt] = dfs(i,j);
                //ret = max(ret, mp2[cnt]=dfs(i,j));
            }
        }
    }

    // 브루트포스 알고리즘
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 0이면
            if(mp[i][j]==0) {
                // 상하좌우 연결
                int sum = 1;    // 본인 포함
                set<int> st;    // 이미 더한 집합인지

                for(int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    
                    if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
                    if(st.find(visited[ny][nx]) != st.end()) continue;
                    sum += mp2[visited[ny][nx]];
                    st.insert(visited[ny][nx]);
                }

                ret = max(ret, sum);
            }
        }
    }
    cout << ret;
}
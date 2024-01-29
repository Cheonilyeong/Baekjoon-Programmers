#include <bits/stdc++.h>

using namespace std;

int mx = INT_MIN, color;
int visited[504][504];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<vector<int>> landT;
vector<int> colorSum;

int dfs(int y, int x, int n, int m) {

    int sum = 1;
    
    for(int i = 0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(landT[ny][nx] == 0 || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x];
        sum += dfs(ny,nx,n,m);
    }
    
    return sum;
}

int solution(vector<vector<int>> land) {
    
    landT = land;
    int n = land.size();
    int m = land[0].size();

    // 색칠 해두기
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            // 석유고 방문한 적 없으면
            if(landT[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = ++color;
                colorSum.push_back(dfs(i,j,n,m));
            }
        }
    }
    
    // 브루트포스 (1부터 6까지 뚫기) 
    for(int j = 0; j<m; j++) {
        int cnt = 0;
        set<int> s;
        // 위에서 아래로 훑기
        for(int i = 0; i<n; i++) {
            // 색칠되어있고 더하지 않은 색이면
            if(visited[i][j] != 0 && s.find(visited[i][j]-1) == s.end()) {
                int colorNum = visited[i][j]-1;
                s.insert(colorNum);
                cnt += colorSum[colorNum];
            }
        }
        // 최대값 갱신
        mx = max(mx, cnt);         
    }
    
    return mx;
}
#include <bits/stdc++.h>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int visited[104][104];

int dfs(int y, int x, int m, int n, vector<vector<int>>& copy_picture) {
    
    int cnt = 1;
    
    for(int i = 0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if(copy_picture[ny][nx]!=copy_picture[y][x] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        cnt += dfs(ny, nx, m, n, copy_picture);
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(visited[i][j]==0 && picture[i][j]) {
                visited[i][j] = 1;
                max_size_of_one_area = max(max_size_of_one_area, dfs(i,j,m,n,picture));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
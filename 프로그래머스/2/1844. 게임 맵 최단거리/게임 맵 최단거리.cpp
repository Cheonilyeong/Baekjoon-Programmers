#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps)
{
    int y, x;
    int maxY = maps.size();
    int maxX = maps[0].size();
    int visited[101][101];
    memset(visited, 0, sizeof(visited));
    
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(q.size()) {
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= maxY || nx < 0 || nx >= maxX) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    
    if(visited[maxY-1][maxX-1]) return visited[maxY-1][maxX-1];
    else return -1;
}
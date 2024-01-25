#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));

    int y = 0, x = -1, cnt = 0, i = 0;
    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

    while(cnt != (n * n)) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n ||
           answer[ny][nx]) {
            i = (i + 1) % 4;
        }
        else {
            answer[ny][nx] = ++cnt;
            y = ny;
            x = nx;
        }
    }
    return answer;
}
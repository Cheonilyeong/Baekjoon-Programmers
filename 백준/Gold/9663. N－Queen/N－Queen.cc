#include <bits/stdc++.h>
using namespace std;

int N, ret;
int visited[20][20]; 

void go(int cnt) {
    if (cnt == N) {
        ret++;
        return;
    }

    for (int i = 0; i < N; i++) {
        int y = i;  
        int x = cnt; 

        if (visited[y][x]) continue;

        for (int j = 0; j < N; j++) {
            visited[y][j]++; 
            visited[j][x]++; 
            if (y + j < N && x + j < N) visited[y + j][x + j]++; 
            if (y - j >= 0 && x + j < N) visited[y - j][x + j]++;
        }

        go(cnt + 1);

        for (int j = 0; j < N; j++) {
            visited[y][j]--; 
            visited[j][x]--; 
            if (y + j < N && x + j < N) visited[y + j][x + j]--; 
            if (y - j >= 0 && x + j < N) visited[y - j][x + j]--; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    go(0);

    cout << ret;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, ret=INT_MAX;
char mp[54][54];

int cnt(int y, int x) {
    char c;
    int count = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int ny = y + i;
            int nx = x + j;

            if(!(ny & 1) && !(nx & 1)) c = 'W';
            else if((ny & 1) && (nx & 1)) c = 'W';
            else c = 'B';
            if(mp[ny][nx] == c) count++;
        }
    }
    
    return min(count, 64-count);
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    for(int i = 0; i <= N-8; i++) {
        for(int j = 0; j <= M-8; j++) {
            ret = min(ret, cnt(i,j));
        }
    }

    cout << ret;
}
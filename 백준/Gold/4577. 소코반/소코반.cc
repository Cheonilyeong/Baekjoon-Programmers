#include <bits/stdc++.h>
using namespace std;

int R, C, y, x, gameCnt;
char mp[20][20];
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1) {
        cin >> R >> C;
        if(R == 0 && C == 0) break;

        // 맵 받기
        int pCnt = 0; // 비어있는 목표점 개수
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> mp[i][j];
                if(mp[i][j] == 'w' || mp[i][j] == 'W') y=i, x=j;
                if(mp[i][j] == '+') pCnt++;
            }
        }

        // 시뮬레이션
        cin >> s;
        for(char c : s) {
            if(pCnt == 0 && mp[y][x] != 'W') continue;

            if(c == 'U') {
                int ny = y - 1;
                int nx = x;
                // 벽이면
                if(mp[ny][nx] == '#') continue;
                // 빈공간이면 {
                else if(mp[ny][nx] == '.') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 박스면
                else if(mp[ny][nx] == 'b') {
                    // 박스 밀고
                    if(mp[ny-1][nx] == '.') mp[ny-1][nx] = 'b';
                    else if(mp[ny-1][nx] == '+') mp[ny-1][nx] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점 위에 올라가있는 박스면
                else if(mp[ny][nx] == 'B') {
                    // 박스 밀고
                    if(mp[ny-1][nx] == '.') mp[ny-1][nx] = 'b';
                    else if(mp[ny-1][nx] == '+') mp[ny-1][nx] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'W';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점이면
                else if(mp[ny][nx] == '+') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'W', pCnt--;
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }

                y = ny;
                x = nx;
            }
            if(c == 'D') {
                int ny = y + 1;
                int nx = x;
                // 벽이면
                if(mp[ny][nx] == '#') continue;
                // 빈공간이면 {
                else if(mp[ny][nx] == '.') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 박스면
                else if(mp[ny][nx] == 'b') {
                    // 박스 밀고
                    if(mp[ny+1][nx] == '.') mp[ny+1][nx] = 'b';
                    else if(mp[ny+1][nx] == '+') mp[ny+1][nx] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점 위에 올라가있는 박스면
                else if(mp[ny][nx] == 'B') {
                    // 박스 밀고
                    if(mp[ny+1][nx] == '.') mp[ny+1][nx] = 'b';
                    else if(mp[ny+1][nx] == '+') mp[ny+1][nx] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'W';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점이면
                else if(mp[ny][nx] == '+') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'W', pCnt--;
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }

                y = ny;
                x = nx;
            }
            if(c == 'L') {
                int ny = y;
                int nx = x - 1;
                // 벽이면
                if(mp[ny][nx] == '#') continue;
                // 빈공간이면 {
                else if(mp[ny][nx] == '.') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 박스면
                else if(mp[ny][nx] == 'b') {
                    // 박스 밀고
                    if(mp[ny][nx-1] == '.') mp[ny][nx-1] = 'b';
                    else if(mp[ny][nx-1] == '+') mp[ny][nx-1] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점 위에 올라가있는 박스면
                else if(mp[ny][nx] == 'B') {
                    // 박스 밀고
                    if(mp[ny][nx-1] == '.') mp[ny][nx-1] = 'b';
                    else if(mp[ny][nx-1] == '+') mp[ny][nx-1] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'W';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점이면
                else if(mp[ny][nx] == '+') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'W', pCnt--;
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }

                y = ny;
                x = nx;
            }
            if(c == 'R') {
                int ny = y;
                int nx = x + 1;
                // 벽이면
                if(mp[ny][nx] == '#') continue;
                // 빈공간이면 {
                else if(mp[ny][nx] == '.') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 박스면
                else if(mp[ny][nx] == 'b') {
                    // 박스 밀고
                    if(mp[ny][nx+1] == '.') mp[ny][nx+1] = 'b';
                    else if(mp[ny][nx+1] == '+') mp[ny][nx+1] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'w';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점 위에 올라가있는 박스면
                else if(mp[ny][nx] == 'B') {
                    // 박스 밀고
                    if(mp[ny][nx+1] == '.') mp[ny][nx+1] = 'b';
                    else if(mp[ny][nx+1] == '+') mp[ny][nx+1] = 'B', pCnt--;
                    else continue;
                    // 캐릭터 이동
                    mp[ny][nx] = 'W';
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }
                // 목표점이면
                else if(mp[ny][nx] == '+') {
                    // 캐릭터 이동
                    mp[ny][nx] = 'W', pCnt--;
                    if(mp[y][x] == 'w') mp[y][x] = '.';
                    else if(mp[y][x] == 'W') mp[y][x] = '+', pCnt++;
                }

                y = ny;
                x = nx;
            }
        }

        // 결과 출력
        if(pCnt == 0 && mp[y][x] != 'W') cout << "Game " << ++gameCnt << ": complete\n";
        else cout << "Game " << ++gameCnt << ": incomplete\n";
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << mp[i][j];
            }
            cout << '\n';
        }
    }
}
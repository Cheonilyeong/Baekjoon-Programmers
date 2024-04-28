#include <bits/stdc++.h>
using namespace std;

int N, M, mp[504][504], psum1[504][504], psum2[504][504], ret;
int dy1[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx1[] = {-3, -2, -1, 0, 1, 0, -1, -2};
int dy2[] = {-3, -2, -1, 0, 1, 0, -1, -2};
int dx2[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy3[] = {1, 1, -1};
int dx3[] = {0, 1, 1};
int dy4[] = {0, 1, 1};
int dx4[] = {1, 1, -1};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> mp[i][j];
            psum1[i][j] = psum1[i][j-1] + mp[i][j];
            psum2[i][j] = psum2[i-1][j] + mp[i][j];
        }
    }    

    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= M; x++) {
            
            // ㅡ or ㄴ or ㅗ
            if(x >= 3) {
                for(int i = 0; i < 8; i++) {
                    int ny1 = y + dy1[i];
                    int nx1 = x + dx1[i];

                    ret = max(ret, psum1[y][x]-psum1[y][x-3]+mp[ny1][nx1]);
                }
            }

            if(y >= 3) {
                for(int i = 0; i < 8; i++) {
                    int ny2 = y + dy2[i];
                    int nx2 = x + dx2[i];

                    ret = max(ret, psum2[y][x]-psum2[y-3][x]+mp[ny2][nx2]);
                }
            }

            // ㅁ or ㄹ
            if(x >= 2) {
                for(int i = 0; i < 3; i++) {
                    int ny3 = y + dy3[i];
                    int nx3 = x + dx3[i];

                    ret = max(ret, psum1[y][x]-psum1[y][x-2]+ psum1[ny3][nx3]-psum1[ny3][nx3-2]);
                }
            }
            
            if(y >= 2) {
                for(int i = 0; i < 3; i++) {
                    int ny4 = y + dy4[i];
                    int nx4 = x + dx4[i];
                    
                    ret = max(ret, psum2[y][x]-psum2[y-2][x]+ psum2[ny4][nx4]-psum2[ny4-2][nx4]);
                }
            }
            //cout << ret << ' ';
        }
        //cout << '\n';
    }

    cout << ret;
}
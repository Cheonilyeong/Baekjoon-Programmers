#include <bits/stdc++.h>
using namespace std; 

int T, N, M, num;
int r1, r2, c1, c2, v;
long long psumX[1004];
long long psumY[1004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N >> M;

        memset(psumY, 0, sizeof(psumY));
        memset(psumX, 0, sizeof(psumX));
        // 배열 정보 받기
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> num;
                psumY[j] += num;
                psumX[i] += num;
            }
        }

        // 연산
        while(M--) {
            cin >> r1 >> c1 >> r2 >> c2 >> v;

            for(int i = r1; i <= r2; i++) {
                psumX[i] += (c2 - c1 + 1) * v;
            }
            for(int i = c1; i <= c2; i++) {
                psumY[i] += (r2- r1 + 1) * v;
            }
        }
       
        // 행 합
        for(int i = 1; i <= N; i++) {
            cout << psumX[i] << ' ';
        }
        cout << '\n';

        // 열 합
        for(int i = 1; i <= N; i++) {
            cout << psumY[i] << ' ';
        }
        cout << '\n';
    }
}
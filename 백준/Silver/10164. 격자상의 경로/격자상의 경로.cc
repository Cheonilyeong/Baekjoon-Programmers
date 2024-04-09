#include <bits/stdc++.h>
using namespace std;

int N, M, K, dp[17][17];
int KY, KX;

int check(int startY, int startX, int endY, int endX) {

    for(int i = startY; i <= endY; i++) {
        for(int j = startX; j <= endX; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[endY][endX];
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    KY = K/M;
    KX = K%M;
    if(KX == 0) {KY--; KX = M;}
    KX--;

    dp[0][1] = 1;
    if(K == 0 || K == N*M) {
        check(1,1,N,M);
    }
    else {
        check(1,1,KY+1,KX+1);
        check(KY+1,KX+1,N,M);
    }

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= M; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[N][M];
}
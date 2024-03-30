#include <bits/stdc++.h>
using namespace std;

int N, num, K, psum[500004], dp[50004][4];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> num;
        psum[i] = psum[i-1] + num;
    }

    cin >> K;

    for(int i = 1; i <= 3; i++) {
        for(int j = i * K; j <= N; j++) {
            dp[j][i] = max(dp[j-1][i], dp[j-K][i-1]+(psum[j]-psum[j-K]));
        }
    }

    cout << dp[N][3];
}
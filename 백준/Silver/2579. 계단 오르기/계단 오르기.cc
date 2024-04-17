#include <bits/stdc++.h>
using namespace std;

int N, v[304], dp[304][3], ret=INT_MIN;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < N; i++) {
        // 한칸 전진
        dp[i+1][2] = dp[i][1]+v[i];
        // 두칸 전진
        dp[i+2][1] = max(dp[i][1]+v[i], dp[i][2]+v[i]);
    }

    cout << max(dp[N][1]+v[N], dp[N][2]+v[N]);
}
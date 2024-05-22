#include <bits/stdc++.h>
using namespace std;

long long N, W[1004], E[1004], dp[1004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    // 부품 받기
    for(int i = 1; i <= N; i++) {
        cin >> W[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> E[i];
    }

    // dp
    long long W_max, E_max;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i-1] + W[i] * E[i];
        W_max = W[i];
        E_max = E[i];
        for(int j = i-1; j >= 1; j--) {
            W_max = max(W_max, W[j]);
            E_max = max(E_max, E[j]);
            dp[i] = min(dp[i], dp[j-1] + W_max * E_max);
        }
    }

    cout << dp[N];
}

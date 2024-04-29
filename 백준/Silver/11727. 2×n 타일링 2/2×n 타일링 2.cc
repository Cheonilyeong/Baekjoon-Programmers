#include <bits/stdc++.h>
using namespace std;

int N, dp[1004];

void memoization() {

    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= 1000; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
        dp[i] %= 10007;
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);

    cin >> N;

    memoization();
    
    cout << dp[N];
}
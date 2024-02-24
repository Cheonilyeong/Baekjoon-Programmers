#include <bits/stdc++.h>
using namespace std;

int n, ai, bi, pai, pbi;
long long dp[1004][2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        
        cin >> ai >> bi;

        if(i == 0) {
            dp[0][0] = bi;
            dp[0][1] = ai;
        }
        else {
            dp[i][0] = max(dp[i-1][0] + (abs(ai-pai)+bi), dp[i-1][1] + (abs(ai-pbi)+bi));
            dp[i][1] = max(dp[i-1][0] + (abs(bi-pai)+ai), dp[i-1][1] + (abs(bi-pbi)+ai));
        }

        pai = ai;
        pbi = bi;
    }

    cout << max(dp[n-1][0],dp[n-1][1]);
}
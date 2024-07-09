#include <bits/stdc++.h>
using namespace std;

int N, isHappy;
double HH, HS, SH, SS;
double dp[1004][2];

int main() {
    ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);

    cin >> N >> isHappy;
    cin >> HH >> HS >> SH >> SS;

    if(isHappy) {
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    else {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    
    for(int i = 1; i <= N; i++) {
        // Happy
        dp[i][0] = (dp[i-1][0]*HH) + (dp[i-1][1]*SH);
        // Sad
        dp[i][1] = (dp[i-1][0]*HS) + (dp[i-1][1]*SS);
    }

    cout << (int)round(dp[N][0]*1000*10)/10 << '\n';
    cout << (int)round(dp[N][1]*1000*10)/10;
}
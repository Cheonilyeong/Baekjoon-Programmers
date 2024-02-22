#include <bits/stdc++.h>
using namespace std;

int N, ret = 1, resL, resR;
int dp[100004][2];
string a, b;

int cal(int A, char op, int B) {
    if(op == '+') return A + B;
    if(op == '-') return A - B;
    if(op == '*') return A * B;
    if(op == '/') return A / B;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = 1; i <= N; i++) {
        cin >> a >> b;

        if(dp[i-1][0] > 0) {
            dp[i][0] = max(cal(dp[i-1][0],a[0],a[1]-'0'), cal(dp[i-1][0],b[0],b[1]-'0'));
        }
        dp[i][1] = max(max(cal(dp[i-1][1],a[0],a[1]-'0'), cal(dp[i-1][1],b[0],b[1]-'0')), dp[i-1][0]);

        if(dp[i][0] <= 0 && dp[i][1] <= 0) {cout << "ddong game"; exit(0);}
    }

    if(dp[N][0] > 0 || dp[N][1] > 0) cout << max(dp[N][0], dp[N][1]);
}
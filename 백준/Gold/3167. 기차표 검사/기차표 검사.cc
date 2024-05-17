#include <bits/stdc++.h>
using namespace std;

int N, K, dp[1004][2], mnRet, mxRet;
vector<pair<int,int>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    v.resize(N+3);
    for(int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // 최소가 되게 -> 검사 받은 사람 우선으로 내리게
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];

        // a명 내리기
        for(int j = 0; j < v[i].first; j++) {
            if(dp[i][0]) dp[i][0]--;
            else {dp[i][1]--; cnt++;}
        }
        // b명 태우기
        dp[i][1] += v[i].second;

        // 검사
        if(K==1 || i%K==1) {
            // 탑승 인원 모두 검사 처리
            dp[i][0] += dp[i][1];
            dp[i][1] = 0;
        }
    }
    mnRet = cnt;

    // 최대가 되게 -> 검사 안 받은 사람들은 우선 내리게
    cnt = 0;
    for(int i = 1; i <= N; i++) {
        
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];

        // a명 내리기
        for(int j = 0; j < v[i].first; j++) {
            if(dp[i][1]) {dp[i][1]--; cnt++;}
            else dp[i][0]--;
        }
        // b명 태우기
        dp[i][1] += v[i].second;
        
        
        // 검사 타임
        if(K==1 || i%K==1) {
            // 탑승 인원 모두 검사 처리
            dp[i][0] += dp[i][1];
            dp[i][1] = 0;
        }

    }
    mxRet = cnt;

    cout << mnRet << ' ' << mxRet;
}
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n, m;
long long ret;
string s;

int main(void) {

    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        cin >> s;
    }

    // 모든 경우의 수 (2의 20승 -> 백만)
    for(int i = 0; i < (1 << n); i++) {

        int cnt = 0, pre, mx = 0;
        long long sum = 1;
        // 제일 긴 롤러코스터 길이 구하기
        for(int j = 0; j<n; j++) {
            if(j == 0) {
                cnt = 1;
                pre = (i & (1 << j)) > 0 ? 1 : 0; // (i & (1 << j)) >> j
            }
            // 지상->지하 or 지하->지상
            else if(pre != (i & (1 << j)) > 0 ? 1 : 0) {
                cnt++;
                pre = (i & (1 << j)) > 0 ? 1 : 0;
            }
            // 지상->지상 or 지하->지하
            else {
                cnt = 1;
                pre = (i & (1 << j)) > 0 ? 1 : 0;
            }
            mx = max(mx, cnt);

            // 경우의 수
            if(i & (1 << j)) sum = (sum % MOD) * (11 % MOD);
            else sum = (sum % MOD) * (5 % MOD);
            
            if(mx > m) break;
        }
        sum %= MOD;

        if(mx == m) ret = (ret % MOD) + (sum % MOD);
    }
    ret %= MOD;

    cout << ret;
}
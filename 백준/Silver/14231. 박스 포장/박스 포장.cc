#include <bits/stdc++.h>
using namespace std;

int N, a, ret = 1;
int dp[5004];
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        
    }

    for(int i = 1; i <= N; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }            
        }
        ret = max(ret, dp[i]);
    }
    cout << ret;
}
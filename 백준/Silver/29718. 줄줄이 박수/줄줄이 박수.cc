#include <bits/stdc++.h>
using namespace std;

int N, M, A, num, mx = INT_MIN;
int cnt[2004], psum[2004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> num;
            cnt[j] += num;
        }
    }

    cin >> A;
    
    for(int i = 1; i <= M; i++) {
        psum[i] = psum[i-1] + cnt[i];
    }

    for(int i = 1; i <= M; i++) {
        mx = max(mx, psum[i-1+A] - psum[i-1]);
    }

    cout << mx;
}
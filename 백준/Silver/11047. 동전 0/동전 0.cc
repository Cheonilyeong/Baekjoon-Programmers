#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = N-1; i >= 0; i--) {
        cnt += K/v[i];
        K %= v[i];
    }

    cout << cnt;
}
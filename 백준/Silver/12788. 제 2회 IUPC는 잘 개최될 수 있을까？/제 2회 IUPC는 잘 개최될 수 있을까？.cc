#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> pens;

int main() {
    ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M >> K;

    pens.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> pens[i];
    }

    sort(pens.begin(), pens.end());

    int cnt = 0;
    int ret = 0;
    
    for(int i = N-1; i >= 0; i--) {
        if(cnt >= M*K) break;
        cnt += pens[i];
        ret++;
    }

    if(cnt >= M*K) cout << ret;
    else cout << "STRESS";
}
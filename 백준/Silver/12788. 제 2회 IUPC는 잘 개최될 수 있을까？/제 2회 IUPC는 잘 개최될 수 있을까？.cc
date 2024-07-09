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
    int index = N-1;
    while(true) {
        if(cnt >= M*K) break;
        if(index == -1) break;
        cnt += pens[index--];
        ret++;
    }

    if(cnt >= M*K) cout << ret;
    else cout << "STRESS";
}
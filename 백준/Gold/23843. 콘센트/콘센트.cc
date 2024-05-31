// 23843 콘센트
#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    vector<long long> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < N; i++) {
        if(pq.size() != M) {
            pq.push(v[i]);
        }
        else {
            long long time = pq.top() + v[i];
            pq.pop();
            pq.push(time);
        }
    }

    while(pq.size()) {
        ret = max(ret, pq.top());
        pq.pop();
    }

    cout << ret;
}
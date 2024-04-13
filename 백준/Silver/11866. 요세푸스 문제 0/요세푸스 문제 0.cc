#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    deque<int> dq;
    for(int i = 0; i < N; i++) {
        dq.push_back(i+1);
    }

    while(dq.size()) {
        int x;
        for(int i = 0; i < K-1; i++) {
            x = dq.front(); dq.pop_front();
            dq.push_back(x);
        }
        x = dq.front(); dq.pop_front();
        v.push_back(x);
    }

    cout << "<";
    for(int i = 0; i < N-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[N-1] << ">";
}
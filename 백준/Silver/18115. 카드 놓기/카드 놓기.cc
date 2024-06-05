#include <bits/stdc++.h>
using namespace std;

int N, num;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    deque<int> dq;
    int card = 1;
    for(int i = N-1; i >= 0; i--) {
        if(v[i] == 1) {
            dq.push_front(card++);
        }
        if(v[i] == 2) {
            int t = dq.front();
            dq.pop_front();
            dq.push_front(card++);
            dq.push_front(t);
        }
        if(v[i] == 3) {
            dq.push_back(card++);
        }
    }

    while(dq.size()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
}
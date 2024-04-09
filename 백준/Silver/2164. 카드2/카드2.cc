#include <bits/stdc++.h>
using namespace std;

int N, ret;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    deque<int> dq;
    for(int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    while(dq.size() != 1) {
        int front = dq.front(); dq.pop_front();
        
        if(dq.size() == 1) {
            ret = dq.front();
            break;
        }
        else {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    if(ret == 0) cout << dq.front();
    else cout << ret;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll A, B, ret=-1;
queue<pair<ll ,ll>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B;

    q.push({A,1});

    while(q.size()) {
        auto it = q.front(); q.pop();
        ll now = it.first;
        ll cnt = it.second;

        if(now == B){
            ret = cnt;
            break;
        }

        // 2배
        long long next = now*2;
        if(next <= B) {
            q.push({next,cnt+1});
        }
        // 뒤에 1
        next = now*10+1;
        if(next <= B) {
            q.push({next,cnt+1});
        }
    }

    cout << ret;
}
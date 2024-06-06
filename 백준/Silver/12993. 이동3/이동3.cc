#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y;

ll pow(ll a, ll b) {
    ll result = 1;
    while(b--) {
        result *= a;
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x >> y;

    queue<tuple<ll,ll,ll>> q;
    q.push({0,0,0});

    bool flag = false;
    while(q.size()) {
        auto now = q.front(); q.pop();
        ll nowX = get<0>(now);
        ll nowY = get<1>(now);
        ll k = get<2>(now);
        
        if(nowX == x && nowY == y) {
            flag = true;
            break;
        }

        // x좌표 증가
        ll nextX = nowX + pow(3,k);
        ll nextY = nowY;
        if(nextX <= x && nextY <= y) {
            q.push({nextX, nextY, k+1});    
        }

        // y좌표 증가
        nextX = nowX;
        nextY = nowY + pow(3,k);
        if(nextX <= x && nextY <= y) {
            q.push({nextX, nextY, k+1});
        }
    }

    if(flag) cout << 1;
    else cout << 0;
}
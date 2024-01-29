// 개미가 부딪힐 때를 잘 생각해 보자
#include <bits/stdc++.h>

using namespace std;

int tc, l, n, pos;

int main(void) {

    cin >> tc;
    while(tc--) {
        
        int mn=0, mx=0;

        cin >> l >> n;

        while(n--) {
            cin >> pos;

            int shortLength = min(pos-0, l-pos); // 자의 가까운 끝까지의 거리
            int longLength = max(pos-0, l-pos);  // 자의 먼 끝까지의 거리

            mn = max(mn, shortLength);
            mx = max(mx, longLength);
        }

        cout << mn << ' ' << mx << '\n';
    }
}
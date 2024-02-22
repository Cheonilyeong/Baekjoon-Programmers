#include <bits/stdc++.h>
using namespace std;

int T, n, a;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--) {

        cin >> n;

        map<int,int> mp;
        int mx = -1, cnt = 1, sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            mp[i] = a;
            sum += a;
            if(a > mp[mx]) {mx = i; cnt = 1;}
            else if(a == mp[mx]) cnt++;
        }

        if(cnt >= 2) cout << "no winner" << '\n';
        else if(mp[mx] > sum / 2) cout << "majority winner " << mx << '\n';
        else if(mp[mx] <= sum / 2) cout << "minority winner " << mx << '\n';
    }
}
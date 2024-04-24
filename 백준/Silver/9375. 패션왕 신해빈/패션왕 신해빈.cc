#include <bits/stdc++.h>
using namespace std;

int T, N;
string s, t;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        map<string,int> mp;
        while(N--) {
            cin >> s >> t;
            mp[t]++;
        }

        int ret = 1;
        for(auto it : mp) {
            ret *= (it.second+1);
        }

        cout << ret-1 << '\n';
    }
}
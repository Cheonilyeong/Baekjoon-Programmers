#include <bits/stdc++.h>
using namespace std;

int N, M;
string site, pswd;
map<string, string> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    while(N--) {
        cin >> site >> pswd;
        mp[site] = pswd;
    }

    while(M--) {
        cin >> site;
        cout << mp[site] << '\n';
    }
}
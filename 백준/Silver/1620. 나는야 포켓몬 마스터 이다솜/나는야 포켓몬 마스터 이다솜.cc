#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
vector<string> v;
map<string,int> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    v.resize(N+1);
    for(int i = 0; i < N; i++) {
        cin >> s;
        v[i+1] = s;
        mp[s] = i+1;
    }

    for(int i = 0; i < M; i++) {
        cin >> s;
        if(isalpha(s[0])) {
            cout << mp[s] << '\n';
        }
        else {
            cout << v[atoi(s.c_str())] << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<string,int> m;
vector<string> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N+M; i++) {
        cin >> s;
        m[s]++;
        if(m[s]==2) v.push_back(s);
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(string s : v) {
        cout << s << '\n';
    }
}
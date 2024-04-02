#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
string s;
vector<int> v[30];

int check(int a, int b) {

    int cnt = 0;

    for(int i : v[a]) {
        if(i == b) {
            cnt++;
            break;
        }
        cnt += check(i, b);
    }

    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    getline(cin,s);
    for(int i = 0; i < n; i++) {
        getline(cin,s);
        a = s.front() - 'a';
        b = s.back() - 'a';
        v[a].push_back(b);
    }

    cin >> m;

    getline(cin,s);
    for(int i = 0; i < m; i++) {
        getline(cin,s);
        a = s.front() - 'a';
        b = s.back() - 'a';
        if(check(a, b)) cout << 'T' << '\n';
        else cout << 'F' << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

string s;
string t;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin >> s) {
        if(s == "0") break;

        t = s;
        reverse(t.begin(), t.end());

        if(t == s) {
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(void) {
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    cout << (s == t);
}
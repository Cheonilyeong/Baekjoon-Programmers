#include <bits/stdc++.h>
using namespace std;

int a, b, c, num, cnt[11];
string s;

int main(void) {

    cin >> a >> b >> c;
    num = a * b * c;

    s = to_string(num);
    for(char c : s) {
        cnt[c - '0']++;
    }

    for(int i = 0; i <= 9; i++) {
        cout << cnt[i] << '\n';
    }
}
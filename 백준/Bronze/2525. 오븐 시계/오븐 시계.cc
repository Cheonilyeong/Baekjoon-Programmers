#include <bits/stdc++.h>

using namespace std;

int h, m, t;

int main(void) {
    cin >> h >> m >> t;
    h += t/60;
    m += t%60;
    h += m/60;
    m %= 60;
    h %= 24;
    cout << h << ' ' << m;
}
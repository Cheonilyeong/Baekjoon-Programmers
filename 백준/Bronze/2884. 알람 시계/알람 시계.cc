#include <bits/stdc++.h>

using namespace std;

int h, m;

int main(void) {
    cin >> h >> m;
    if(m < 45) {
        if(h == 0) h = 23; else h--;
        m = 60 - (45 - m);
    } 
    else m -= 45;
    cout << h << ' ' << m;
}
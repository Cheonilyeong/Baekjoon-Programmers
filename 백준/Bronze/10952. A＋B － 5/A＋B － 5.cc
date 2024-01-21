#include <bits/stdc++.h>

using namespace std;

int a, b;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> a >> b;
        if(!a && !b) break;
        cout << a + b << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

int a, b, t;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << '\n';
    }
}
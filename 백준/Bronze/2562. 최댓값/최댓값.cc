#include <bits/stdc++.h>

using namespace std;

int a, mx = INT_MIN, idx = -1;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        cin >> a;
        if(mx < a) {
            mx = a;
            idx = i + 1;
        }
    }
    cout << mx << '\n' << idx;
}
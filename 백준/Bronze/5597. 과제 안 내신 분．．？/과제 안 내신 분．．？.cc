#include <bits/stdc++.h>

using namespace std;

int a, check[33];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 28; i++) {
        cin >> a;
        check[a] = 1;
    }
    for(int i = 1; i <= 30; i++) {
        if(check[i] == 0) cout << i << '\n';
    }
}
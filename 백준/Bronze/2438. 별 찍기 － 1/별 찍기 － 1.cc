#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}
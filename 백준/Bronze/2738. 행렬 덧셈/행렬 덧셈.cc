#include <bits/stdc++.h>
using namespace std;

int a, b, n, cnt[104][104];
int main(void) {
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> n;
            cnt[i][j] += n;
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> n;
            cnt[i][j] += n;
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    }
}
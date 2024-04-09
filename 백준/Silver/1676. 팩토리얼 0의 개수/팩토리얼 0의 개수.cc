#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        int now = i;
        while(now % 5 == 0) {
            now /= 5;
            cnt++;
        }
    }

    cout << cnt;
}
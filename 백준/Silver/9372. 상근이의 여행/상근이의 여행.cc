#include <bits/stdc++.h>
using namespace std;

int T, N, M, a, b;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N >> M;

        for(int i = 0; i < M; i++) {
            cin >> a >> b;
        }

        cout << N-1 << '\n';
    }
}
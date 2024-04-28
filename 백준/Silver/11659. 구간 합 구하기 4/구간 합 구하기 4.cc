#include <bits/stdc++.h>
using namespace std;

int N, M, num, psum[100004];
int a, b;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int num;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        psum[i] = psum[i-1] + num;
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << '\n';
    }
}
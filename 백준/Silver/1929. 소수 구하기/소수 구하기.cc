#include <bits/stdc++.h>
using namespace std;

int N, M;
int che[1000001];

void era() {

    for(int i = 2; i <= 1000000; i++) {
        if(che[i]) continue;
        for(int j = i*2; j <= 1000000; j+=i) {
            che[j] = 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    che[1] = 1;
    era();
    cin >> M >> N;

    for(int i = M; i <= N; i++) {
        if(che[i] == 0) cout << i << '\n';
    }
}
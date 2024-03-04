#include <bits/stdc++.h>
using namespace std;

int N, ret;
vector<double> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < (1 << N); i++) {
        double sum = 0;

        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                sum += (1 / v[j]);
            }
        }
        
        if(sum >= 0.99 && sum <= 1.01) ret++;
    }

    cout << ret;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            for(int k = j+1; k < N; k++) {
                int sum = v[i] + v[j] + v[k];
                if(sum <= M && sum > ret) ret = sum;
            }
        }
    }

    cout << ret;
}
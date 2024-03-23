#include <bits/stdc++.h>
using namespace std;

int N, boom;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    boom = N-3;
    while(boom--) {
        if(v[0] <= v[N-1]) v[N-1]--;
        else v[0]--;
    }

    cout << max(v[0]-1, v[N-1]-1);
}
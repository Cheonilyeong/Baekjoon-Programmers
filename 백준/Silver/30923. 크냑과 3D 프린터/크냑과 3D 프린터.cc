#include <bits/stdc++.h>
using namespace std;

int N;
long long sum;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i <= N; i++) {
        sum += v[i]*4 + 2;
        sum -= min(v[i],v[i-1])*2;
    }

    cout << sum;
}
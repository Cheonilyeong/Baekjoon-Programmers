#include <bits/stdc++.h>
using namespace std;

int N;
long long ret;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++) {
        ret += abs((i+1) - v[i]);
    }

    cout << ret;
}
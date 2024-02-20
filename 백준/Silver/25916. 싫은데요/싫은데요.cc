#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
long long sum, mx=LLONG_MIN;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 0, right = 0;
    sum = v[left];

    while(right < N) {
        if(sum <= M) {
            mx = max(mx, sum);
            sum += v[++right];
        }
        else if(sum > M) sum -= v[left++];
    }

    cout << mx;
}
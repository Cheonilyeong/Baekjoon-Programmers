#include <bits/stdc++.h>
using namespace std;

long long N, t, a, b, idx, red;
vector<long long> v;

int main(void) {
    cin >> N >> t;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        if(i == 0) red = a;
        else if(a < red) idx++;
        v.push_back(a+b*t);
    }

    sort(v.begin(), v.end());

    cout << v[idx];
}
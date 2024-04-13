#include <bits/stdc++.h>
using namespace std;

int N, num, sum;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }
    
    sort(v.begin(), v.end());

    int n = round(N*0.15);
    for(int i = 0; i < n; i++) {
        sum -= v[0+i];
        sum -= v[N-1-i];
    }

    if(N) cout << round(1.0*sum/(N-2*n));
    else cout << 0;
}
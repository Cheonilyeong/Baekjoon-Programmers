#include <bits/stdc++.h>
using namespace std;

int N, C, W;
long long sum, ret;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 나무, 비용, 가격
    cin >> N >> C >> W;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i <= 10000; i++) {
        sum = 0;
        for(int j = 0; j < N; j++) {
            if(v[j] == i) sum += (v[j]*W);
            else if(v[j] > i) {
                if(v[j] % i == 0) sum += max((v[j]/i)*i*W - (v[j]/i-1)*C, 0);
                else sum += max((v[j]/i)*i*W - (v[j]/i)*C, 0);
            }
        }
        ret = max(ret,sum);
    }
    
    cout << ret;
}
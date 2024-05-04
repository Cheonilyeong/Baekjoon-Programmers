#include <bits/stdc++.h>
using namespace std;

int N, K, num;
vector<int> shared;
vector<int> ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> num;
        shared.push_back(num);
    }
    
    sort(shared.begin(), shared.end());
    for(int i = 0; i < N; i++) {
        cin >> num;
        ret.push_back(max(shared[0]*num,shared[shared.size()-1]*num));
    }

    sort(ret.begin(),ret.end());

    cout << ret[N-K-1];
}
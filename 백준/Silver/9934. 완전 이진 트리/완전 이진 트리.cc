#include <bits/stdc++.h>
using namespace std;

int K, a;
vector<int> v;
vector<int> ret[10];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> K;
    for(int i = 0; i < pow(2, K)-1; i++) {
        cin >> a;
        v.push_back(a);
    }

    for(int i = v.size()/2; i >= 0; i/=2) {
        for(int j = i; j < v.size(); j+=pow(2,K)) {
            cout << v[j] << ' ';
        }
        cout << '\n';
        K--;
        if(i == 0) break;
    }
}
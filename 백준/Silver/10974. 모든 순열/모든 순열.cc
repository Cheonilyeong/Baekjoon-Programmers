#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    do {
        for(int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
}
#include <bits/stdc++.h>
using namespace std;

int N, M, num;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 배열받기
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // 질문받기
    for(int i = 0; i < M; i++) {
        cin >> num;

        int idx = lower_bound(v.begin(), v.end(), num) - v.begin();

        if(idx < N && v[idx] == num) {
            cout << idx << '\n';
        }
        else {
            cout << -1 << '\n';
        }      
    }
}
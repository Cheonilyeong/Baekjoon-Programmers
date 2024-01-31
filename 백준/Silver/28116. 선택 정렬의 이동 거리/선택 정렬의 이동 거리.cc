#include <bits/stdc++.h>
using namespace std;

int N, v[500005], idx[500005], cnt[500005];

int main(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> v[i];
        idx[--v[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        int mnIdx = idx[i];

        cnt[v[i]] += (mnIdx - i);
        cnt[i] += (mnIdx - i);
        
        swap(idx[v[i]], idx[i]);
        swap(v[i], v[mnIdx]);

        cout << cnt[i] << ' ';
    }
}
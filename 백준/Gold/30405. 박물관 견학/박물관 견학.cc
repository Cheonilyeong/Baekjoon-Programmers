#include <bits/stdc++.h>
using namespace std;

int N, M, k, p;
vector<int> num;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> k;

        for(int j = 0; j < k; j++) {
            cin >> p;
            if(j == 0 || j == k-1) num.push_back(p);
        }
    }

    sort(num.begin(), num.end());

    cout << num[N-1];
}
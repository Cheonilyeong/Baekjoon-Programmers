#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        v.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        reverse(v.begin() + a - 1, v.begin() + b);
   }
   for(int i : v) cout << i << ' ';
}
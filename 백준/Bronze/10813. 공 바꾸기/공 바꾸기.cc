#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c, basket[104];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) basket[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        swap(basket[a], basket[b]);
    }
    for(int i = 1; i <= n; i++) 
        cout << basket[i] << ' ';
}
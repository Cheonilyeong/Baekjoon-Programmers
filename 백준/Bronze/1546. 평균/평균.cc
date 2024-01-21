#include <bits/stdc++.h>

using namespace std;

int n, a, mx = INT_MIN;
double sum;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        mx = max(mx, a);
    }
    for(int i : v)  sum += ((double)i / mx * 100);
    cout << sum / n;
}
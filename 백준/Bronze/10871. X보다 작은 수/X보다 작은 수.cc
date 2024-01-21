#include <bits/stdc++.h>

using namespace std;

int a, b, n;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> n;
        v.push_back(n);
    }

    for(int i : v) {
        if(i < b) cout << i << ' ';
    }
}
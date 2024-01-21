#include <bits/stdc++.h>

using namespace std;

int n, a;
map<int,int> mp;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
    }
    cin >> a;
    cout << mp[a];

}
// atoi의 반환형은 int이다.
// long long 으로 반환하고 싶으면 atoll을 사용하면 된다.
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
string num;
vector<ll> ret;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    while(n--) {
        cin >> num;
        reverse(num.begin(), num.end());
        ret.push_back(atoll(num.c_str()));
    }

    sort(ret.begin(), ret.end());

    for(ll i : ret) {
        cout << i << '\n';
    }
}
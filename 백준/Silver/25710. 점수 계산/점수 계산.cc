#include <bits/stdc++.h>
using namespace std;

int N, a, mx = INT_MIN;
map<int,int> mp;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    // 그냥 모든 원소를 넣으면 시간복잡도가 10만*10만이다.
    // 하지만 조건을 보면 N은 10만이지만 원소는 999까지다.
    // 즉 같은 원소가 2번 이상 나오는 것을 제외해주면 시간복잡도를 줄일 수 있다.
    while(N--) {
        cin >> a;
        if(mp[a] < 2) {
            v.push_back(a);
            mp[a]++;
        }
    }

    // 브루트포스
    for(int i = 0; i < v.size()-1; i++) {
        for(int j = i + 1; j < v.size(); j++) {

            string t = to_string(v[i] * v[j]);
            int sum = 0;

            for(char c : t) sum += c - '0';

            mx = max(mx, sum);
        }
    }

    cout << mx;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, num;
string s1, s2;

vector<pair<int, string>> v;
map<string,int> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2;

        int h = atoi(s1.substr(0,2).c_str());
        int m = atoi(s1.substr(3,2).c_str());
        mp[s2]  += h*60 + m;
    }

    for(auto it : mp) {
        string name = it.first;
        int m = it.second;

        int cost = 0;
        if(m <= 100) cost = 10;
        else {
            // 기본요금
            cost = 10;

            // 초과요금
            int m2 = m - 100;
            cost += (3 * (m2/50));
            if(m2 % 50 != 0) {
                cost += 3;
            }
        }
        v.push_back({cost,name});
    }

    sort(v.begin(), v.end(), [](const pair<int,string>& a, const pair<int,string>& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for(auto it : v) {
        cout << it.second << ' ' << it.first << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, T;
string s;

int check(string& a, string& b) {
    
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        if(a[i] != b[i]) cnt++;
    }

    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--) {
        int ret = INT_MAX;
        vector<string> v;
        map<string,int> mp;

        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> s;
            mp[s]++;
        }

        for(auto it : mp) {
            for(int i = 0; i<it.second && i<3; i++) {
                v.push_back(it.first);
            }
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++) {
            for(int j = i+1; j < v.size(); j++) {
                for(int k = j+1; k < v.size(); k++) {
                    ret = min(ret, (check(v[i],v[j])+check(v[j],v[k])+check(v[i],v[k])));
                }
            }
        }

        cout << ret << '\n';
    }
}
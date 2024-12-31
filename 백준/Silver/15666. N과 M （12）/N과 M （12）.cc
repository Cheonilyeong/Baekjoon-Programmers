#include <bits/stdc++.h>
using namespace std;

int N, M, num;
vector<int> v;
set<int> s;

void go(string str, int now, int cnt) {
    if(cnt == M) {
        cout << str << '\n';
        return;
    }

    for(int i = now; i < v.size(); i++) {
        go(str + ' ' + to_string(v[i]), i, cnt + 1);
    }
}

int main() {
    
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> num;
        if(s.find(num) == s.end()) {
            v.push_back(num);
            s.insert(num);
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        go(to_string(v[i]), i, 1);
    }
}
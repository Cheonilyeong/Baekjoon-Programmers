#include <bits/stdc++.h>
using namespace std;

int N, visited[10], mn=INT_MAX;
string s;
vector<string> v;

void go(int cnt, string s) {
    if(cnt == N) {
        mn = min(mn, (int)s.size());
        //cout << s << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = 1;

        string t = s;
        int j = min(t.size(), v[i].size());

        for(j; j>0; j--) {
            if(t.substr(t.size()-j) == v[i].substr(0,j)) {
                t.erase(t.size()-j);
                break;
            }
        }

        go(cnt+1, t+v[i]);
        visited[i] = 0;
    }
}
int main(void) {

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }
    
    go(0, "");
    
    cout << mn;
}
#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;
int visited[104];

int main() {
    
    cin >> t;

    while(t--) {

        cin >> n;

        vector<pair<int,int>> v;
        for(int i = 0; i < n+2; i++) {
            cin >> x >> y;
            v.push_back(pair(x,y));
        }

        vector<int> e[n+2];
        for(int i = 0; i < n+2; i++) {
            for(int j = i+1; j < n+2; j++) {
                int d = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);

                if(d <= 1000) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while(q.size()) {
            int now = q.front(); q.pop();

            for(auto it: e[now]) {
                if(visited[it] == 0) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        if(visited[n+1]) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
        
    }
}
#include <bits/stdc++.h>
using namespace std;
#define next next1

int T, A, B, next, visited[10004];
string t, s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    
    while(T--) {
        cin >> A >> B;

        vector<pair<char,int>> root(10004);
        queue<int> q;
        visited[A] = 1;
        q.push(A);

        while(q.size()) {
            int now = q.front(); q.pop();

            if(visited[B]) break;

            // D
            next = (now << 1) % 10000;
            if(!visited[next]) {
                visited[next]=visited[now]+1;
                q.push(next);
                root[next].first = 'D';
                root[next].second = now;
            }
            // S
            if(now) next = now-1;
            else next = 9999;
            if(!visited[next]) {
                visited[next]=visited[now]+1;
                q.push(next);
                root[next].first = 'S';
                root[next].second = now;
            }
            // L
            next = (now*10+(now/1000)) % 10000;
            if(!visited[next]) {
                visited[next]=visited[now]+1;
                q.push(next);
                root[next].first = 'L';
                root[next].second = now;
            }
            // R
            next = (now/10+(now%10)*1000);
            if(!visited[next]) {
                visited[next]=visited[now]+1;
                q.push(next);
                root[next].first = 'R';
                root[next].second = now;
            }
        }

        int current = B;
        vector<char> ret;
        while(current!=A) {
            //cout << current << ' ';
            ret.push_back(root[current].first);
            current = root[current].second;
        }
        for(int i = ret.size()-1; i >= 0; i--) {
            cout << ret[i];
        }
        cout << '\n';

        memset(visited, 0, sizeof(visited));
    }
}
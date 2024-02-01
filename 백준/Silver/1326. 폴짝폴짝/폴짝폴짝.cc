#include <bits/stdc++.h>
#define end ee
using namespace std;

int N, start, end, visited[10004];
bool flag = false;

int main(void) {

    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cin >> start >> end;

    queue<int> q;
    q.push(start-1);
    visited[start-1] = 1;

    while(q.size()) {
        int now = q.front();
        q.pop();

        if(now == end-1) {
            cout << visited[now] -1;
            flag = true;
            break;
        }

        for(int next = now; next < N; next += v[now]) {
            if(visited[next] == 0) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }

        for(int next = now; next >= 0; next -= v[now]) {
            if(visited[next] == 0) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

    if(!flag) cout << -1;
}
#include <bits/stdc++.h>
using namespace std;

int N, ret=INT_MAX, visited[50004];
vector<int> v;
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i*i <= N; i++) {
        v.push_back(i*i);
        visited[i*i] = 1;
        q.push(i*i);
    }

    while(q.size()) {
        int now = q.front(); q.pop();
        
        if(visited[N]) break;

        for(int i : v) {
            int next = now + i;
            if(next > N) continue;
            if(visited[next]) continue;

            if(next <= N) {
                visited[next] = visited[now]+1;
                q.push(next);
            }
        }
    }

    cout << visited[N];
}
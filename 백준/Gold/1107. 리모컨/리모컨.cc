#include <bits/stdc++.h>
using namespace std;

int N, M, num, checked[15], visited[1111111];
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> num;
        checked[num] = 1;
    }

    visited[100] = 1;
    visited[99] = 2;
    visited[101] = 2;
    q.push(99);
    q.push(101);

    for(int i = 0; i <= 1111111; i++) {
        string s = to_string(i);
        bool flag = true;
        for(char c : s) {
            if(checked[c-'0']) {
                flag = false;
                break;
            }
        }
        if(!flag || visited[i]) continue;
        visited[i] = s.size()+1;
        q.push(i);
    }

    while(q.size()) {
        int now = q.front(); q.pop();
        
        int next;
        if(now < N) next = now+1;
        if(now > N) next = now-1;

        if(next < 0 || next >= 1111111) continue;
        
        if(visited[next] == 0 || visited[next] > visited[now]+1) {
            visited[next] = visited[now] + 1;
            q.push(next);
        }

    }

    cout << visited[N] - 1;
}
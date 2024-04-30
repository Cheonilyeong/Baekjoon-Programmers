#include <bits/stdc++.h>
using namespace std;

int N, M, num, p, visited[54], ret;
vector<int> v[54];
vector<int> v2[54];
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // N:사람의 수 M:파티의 수
    cin >> N >> M;

    // 진실을 아는 사람의 수
    cin >> num;
    while(num--) {
        cin >> p;
        visited[p] = 1;
        q.push(p);
    }

    // 파티
    for(int i = 0; i < M; i++) {
        cin >> num;

        bool flag = false;
        while(num--) {
            cin >> p;
            v[i].push_back(p);
            v2[p].push_back(i);
        }
    }

    while(q.size()) {
        int now = q.front(); q.pop();

        for(int i : v2[now]) {
            for(int j : v[i]) {
                if(visited[j]) continue;
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    
    for(int i = 0; i < M; i++) {
        int cnt = 0;
        for(int j : v[i]) if(visited[j]) cnt++;
        if(cnt==0) ret++;
    }
    cout << ret;
}
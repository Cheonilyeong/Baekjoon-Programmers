#include <bits/stdc++.h>
using namespace std;

int N, A, B, visited[500004][2], ret;
bool flag = false;

int pow(int a, int b) {
    int num = 1;
    for(int i = 0; i < b; i++) {
        num *= a;
    }
    return num;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;

    queue<tuple<int,int,int>> q;
    q.push({A,0,0});
    q.push({B,0,1});
    while(q.size()) {
        auto it = q.front(); q.pop();
        int now = get<0>(it);
        int cnt = get<1>(it);
        int who = get<2>(it);

        int next;
        next = now + pow(2,cnt);
        if(next >= 1 && next <= N) {
            visited[next][who] = cnt+1;
            if(visited[next][who] == visited[next][(who+1)%2]) { flag=true; ret=cnt+1; }
            q.push({next,cnt+1,who});
        }

        next = now - pow(2,cnt);
        if(next >= 1 && next <= N) {
            visited[next][who] = cnt+1;
            if(visited[next][who] == visited[next][(who+1)%2]) { flag=true; ret=cnt+1;}
            q.push({next,cnt+1,who});
        }

        if(flag) break;
    }

    if(flag) cout << ret;
    else cout << -1;
}
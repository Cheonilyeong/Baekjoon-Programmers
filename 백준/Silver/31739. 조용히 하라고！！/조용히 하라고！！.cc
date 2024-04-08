#include <bits/stdc++.h>
using namespace std;

int N, M, K, T, P;
int y, x, s;
int mp[54][54], visited[54][54];
int ret1, ret2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<tuple<int,int,int>> mos;

void dfs(int y, int x, int cnt, int time) {
    if(time > T) return;
    if(ret1 == K) return;

    cnt += mp[y][x];
    ret1 = max(ret1,cnt);

    for(auto it : mos) {
        int mosY = get<0>(it); 
        int mosX = get<1>(it);
        int d = abs(mosY-y) + abs(mosX-x);

        if(visited[mosY][mosX]) continue;

        visited[mosY][mosX] = 1;
        dfs(mosY,mosX,cnt,time+d);
        visited[mosY][mosX] = 0;
    }
}

int check(int y, int x) {

    int cnt = 0;

    for(auto it : mos) {
        int mosY = get<0>(it); 
        int mosX = get<1>(it);
        int mosS = get<2>(it);

        if(mosY == y && mosX == x) {cnt++; continue;}
        int d = abs(mosY-y) + abs(mosX-x);
        if(mosS <= P/d) cnt++;
    }

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> T >> P;

    for(int i = 0; i < K; i++) {
        cin >> y >> x >> s;
        mp[y][x]++;
        mos.push_back({y,x,s});
    }

    // 우정이   
    for(auto it : mos) {
        y = get<0>(it); x = get<1>(it);

        visited[y][x] = 1;
        dfs(y, x, 0, 0);
        visited[y][x] = 0;
    }

    // 아름이
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            ret2 = max(ret2,check(i,j));
        }
    }

    cout << ret1 << ' ' << ret2;
}
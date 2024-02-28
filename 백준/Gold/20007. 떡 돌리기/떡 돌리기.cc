#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int N, M, X, Y, A, B, C, ret = 1, dis;
int dist[1004];
bool flag = true;
vector<pair<int,int>> adj[1004];
vector<int> v;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X >> Y;

    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({C,B});
        adj[B].push_back({C,A});
    }

    // 거리 초기화
    fill(&dist[0], &dist[1004], INF);
    dist[Y] = 0;
    pq.push({0,Y});

    // 다익스트라
    while(!pq.empty()) {

        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;

        for(pair<int,int> it : adj[here]) {
            int there = it.second;
            int there_dist = it.first;
            if(dist[here]+there_dist < dist[there]) {
                dist[there] = dist[here] + there_dist;
                pq.push({dist[there], there});
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(dist[i] * 2 > X || dist[i] == INF) {
            flag = false;
            break;
        }
        else {
            v.push_back(dist[i] * 2);
        }
    }

    sort(v.begin(), v.end());
    for(int i : v) {
        if(dis + i > X) {
            dis = i;
            ret++;
        }
        else {
            dis += i;
        }
    }

    if(flag) cout << ret;
    else cout << -1;
}
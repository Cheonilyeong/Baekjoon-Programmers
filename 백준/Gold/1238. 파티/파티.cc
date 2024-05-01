#include <bits/stdc++.h>
using namespace std;

int N, M, X, u, v, w, ret;
int dist[100004], retDist[100004];
const int INF = 1e9+7;
vector<pair<int,int>> adj[100004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w,v));
    }
    
    for(int startV = 1; startV <= N; startV++) {
        fill(&dist[0], &dist[100003], INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push(make_pair(0,startV));
        dist[startV] = 0;

        while(pq.size()) {
            int here = pq.top().second;
            int here_dist = pq.top().first;
            pq.pop();

            if(dist[here] != here_dist) continue;

            for(auto it : adj[here]) {
                int there = it.second;
                int there_dist = it.first;
                if(dist[there] > dist[here]+there_dist) {
                    dist[there] = dist[here]+there_dist;
                    pq.push(make_pair(dist[there],there));
                }
            }
        }

        if(startV == X) {
            for(int i = 1; i <= N; i++) retDist[i] += dist[i];
        }
        else retDist[startV] += dist[X];
    }

    for(int i = 1; i <= N; i++) {
        ret = max(ret,retDist[i]);
    }

    cout << ret;
}
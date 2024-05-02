#include <bits/stdc++.h>
using namespace std;

int N, E, u, v, w, V1, V2;
tuple<int,int,int> V1Dist, V2Dist;
int dist[805];
vector<pair<int,int>> adj[805];
const int INF = 1e9+7;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }

    cin >> V1 >> V2;

    for(int i = 0; i < 2; i++) {
        int startV;
        if(i==0) startV = V1; 
        else startV = V2;

        fill(&dist[0], &dist[804], INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,startV});
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
                    pq.push({dist[there],there});
                }
            }

            if(i==0) V1Dist = {dist[1],dist[V2],dist[N]};
            else V2Dist = {dist[1],dist[V1],dist[N]};
        }
    }
    if(get<0>(V1Dist)==INF&&get<0>(V2Dist)==INF) cout << -1;
    else if(get<1>(V1Dist)==INF&&get<1>(V2Dist)==INF) cout << -1;
    else if(get<2>(V1Dist)==INF&&get<2>(V2Dist)==INF) cout << -1;
    else {
        int d1 = get<0>(V1Dist)+get<1>(V1Dist)+get<2>(V2Dist);
        int d2 = get<0>(V2Dist)+get<1>(V1Dist)+get<2>(V1Dist);
        cout << min(d1, d2);
    }
}
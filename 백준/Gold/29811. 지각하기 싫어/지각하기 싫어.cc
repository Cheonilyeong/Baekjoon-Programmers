#include <bits/stdc++.h>
using namespace std;

int N, M, K, x, y, a, b;
char c;
vector<int> v;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    v.resize(N+M+1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        pq1.push({v[i],i});
    }
    for(int i = N+1; i <= N+M; i++) {
        cin >> v[i];
        pq2.push({v[i],i});
    }

    cin >> K;
    while(K--) {
        cin >> c;
        
        if(c == 'U') {
            cin >> x >> y;
            v[x] = y;
            if(x <= N) pq1.push({y,x});
            else pq2.push({y,x});
        }

        if(c == 'L') {
            while(1) {
                tie(a,b) = pq1.top();
                if(v[b] == a) {
                    cout << b << ' ';
                    break;
                }
                else {
                    pq1.pop();
                }
            }
            while(1) {
                tie(a,b) = pq2.top();
                if(v[b] == a) {
                    cout << b << '\n';
                    break;
                }
                else {
                    pq2.pop();
                }
            }
        }
        
    }

}
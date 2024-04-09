#include <bits/stdc++.h>
using namespace std;

int T, N, M, num, cnt;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N >> M;

        priority_queue<int> pq;
        queue<pair<int,int>> q;
        cnt = 0;

        for(int i = 0; i < N; i++) {
            cin >> num;
            pq.push(num);
            q.push({i,num});
        }

        while(1) {
            int hi = pq.top();
            auto now = q.front();

            if(now.second == hi) {
                pq.pop();
                q.pop();
                cnt++;
                if(now.first == M) break;
            }
            else {
                q.pop();
                q.push(now);
            }
        }

        cout << cnt << '\n';
    }
}
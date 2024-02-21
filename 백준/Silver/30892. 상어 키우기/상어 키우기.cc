#include <bits/stdc++.h>
using namespace std;

int N, K, T, a;
long long ret;
priority_queue<int, vector<int>, less<int>> pq1;    // max_heap (잡아먹을 수 있는)
priority_queue<int, vector<int>, greater<int>> pq2; // min_heap (잡아먹을 수 없는)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> T;

    for(int i = 1; i <= N; i++) {
        cin >> a;
        if(a < T) pq1.push(a);
        else pq2.push(a);
    }

    ret = T;
    
    while(K--) {
        // 잡아먹을 수 있는 상어가 없으면
        if(pq1.empty()) break;

        // 먹는다
        int t = pq1.top();
        ret += t;
        pq1.pop();

        // 잡아먹을 수 있어진 상어 옮기기
        while(1) {
            if(pq2.empty()) break;
            else if(pq2.top() < ret) {
                t = pq2.top();
                pq2.pop();
                pq1.push(t);
            }
            else break;
        }
    }
    
    cout << ret;
}
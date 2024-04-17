#include <bits/stdc++.h>
using namespace std;

int N, num;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> num;

        if(num == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
}
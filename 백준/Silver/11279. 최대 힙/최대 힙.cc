#include <bits/stdc++.h>
using namespace std;

// 연습
struct compare {
    bool operator() (const int& a, const int& b) {
        return a < b;      
    }
};

int N, num;
priority_queue<int,vector<int>,compare> pq;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> num;

        if(num == 0) {
            if(pq.size()) {
                cout << pq.top() << '\n'; 
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            pq.push(num);
        }
    }
}
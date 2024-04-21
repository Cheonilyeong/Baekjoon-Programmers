#include <bits/stdc++.h>
using namespace std;

int T, N, num;
char C;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;
        
        // pq1-max pq2-min
        priority_queue<int> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        map<int,int> mp;

        while(N--) {
            cin >> C >> num;
            if(C=='I') {
                pq1.push(num);
                pq2.push(num);
                mp[num]++;
            }
            // pop min
            if(C=='D' && num==-1) {
                while(1) {
                    if(pq2.empty()) break;
                    int mn = pq2.top(); pq2.pop();
                    if(mp[mn]) {
                        mp[mn]--;
                        break;
                    }
                }
            }
            // pop max
            if(C=='D' && num==1) {
                while(1) {
                    if(pq1.empty()) break;
                    int mx = pq1.top(); pq1.pop();
                    if(mp[mx]) {
                        mp[mx]--;
                        break;
                    }
                }
            }
        }

        int ret_mx=INT_MIN, ret_mn=INT_MAX;
        while(1) {
            if(pq1.empty()) break;
            int mx = pq1.top(); pq1.pop();
            if(mp[mx]) {
                ret_mx = mx;
                break;
            }
        }

        while(1) {
            if(pq2.empty()) break;
            int mn = pq2.top(); pq2.pop();
            if(mp[mn]) {
                ret_mn = mn;
                break;
            }
        }

        if(ret_mn==INT_MAX && ret_mx==INT_MIN) cout << "EMPTY\n";
        else cout << ret_mx << ' ' << ret_mn << '\n';
    }
}
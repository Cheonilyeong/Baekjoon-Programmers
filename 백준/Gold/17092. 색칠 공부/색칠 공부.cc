#include <bits/stdc++.h>
using namespace std;

long long H, W, N, r, c, ret[11];
int dy[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0};
int dx[] = {-2, -1, 0, -2, -1, 0, -2, -1, 0};
vector<pair<int,int>> v;
set<pair<int,int>> st;
set<pair<int,int>> st2;


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> H >> W >> N;

    for(int i = 0; i < N; i++) {
        cin >> r >> c;
        st.insert(make_pair(r-1,c-1));
        v.push_back(make_pair(r-1,c-1));
    }

    sort(v.begin(), v.end());

    for(auto it : v) {

        for(int i = 0; i < 9; i++) {
            bool flag = true;
            int cnt = 0;

            int startY = it.first + dy[i];
            int startX = it.second + dx[i];

            if(st2.find({startY,startX}) != st2.end()) continue;

            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    int ny = startY + j;
                    int nx = startX + k;
                    if(ny < 0 || ny >= H || nx < 0 || nx >= W) {flag = false; break;}
                    if(st.find({ny,nx}) != st.end()) cnt++;
                }
                if(!flag) break;
            }

            if(flag) {
                ret[cnt]++;
                st2.insert(make_pair(startY, startX));
            }
        }
    }

    ret[0] = (H-2) * (W-2) - st2.size();
    for(int i = 0; i <= 9; i++) {
        cout << ret[i] << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, SF, mx, l, r, cnt, ret;
float C;
vector<int> v;
int main(void) {

    cin >> C;
    SF = C/(0.99); if(SF > 2) SF = 2;
    
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    l = 0, r = 0;
    while(l <= r && r < N) {
        if(v[r] == 0) {
            if(cnt < SF) {
                cnt++;
                r++;
            }
            else {
                while(v[l] != 0) {l++;}
                l++;
                r++;
            }
        }
        else {
            r++;
        }
        ret = max(ret,(r-l));
    }

    cout << ret << '\n' << mx;
}
#include <bits/stdc++.h>
using namespace std;

int W, L, N, ret;
vector<int> up[1004];
vector<int> down[1004];
int downMn[1004];
int upMn[1004];
map<vector<pair<int,int>>, int> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> W >> L >> N;

    for(int i = 0; i < N; i++) {
        up[i].resize(L); down[i].resize(L);
        for(int j = 0; j < L; j++) {
            cin >> up[i][j];
            upMn[i] = (upMn[i]==0||upMn[i]>up[i][j]) ? up[i][j] : upMn[i];
        }
        for(int j = 0; j < L; j++) {
            cin >> down[i][j]; 
            downMn[i] = (downMn[i]==0||downMn[i]>down[i][j]) ? down[i][j] : downMn[i];
        }
    }

    ret = N;

    for(int i = 0; i < N; i++) {
        bool flag = false;
        for(int j = i+1; j < N; j++) {

            // 0도 같은 패턴인지
            int cnt = 0;
            for(int k = 0; k < L; k++) {
                int a = down[i][k] - downMn[i];
                int b = W - up[i][k] - down[i][k];

                int c = down[j][k] - downMn[j];
                int d = W - up[j][k] - down[j][k];
                
                if(a == c && b == d) cnt++;
                //cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
            }
            if(cnt == L) flag = true;

            cnt = 0;
            // 180도 돌렸을 때 같은 패턴인지
            for(int k = 0; k < L; k++) {
                int a = down[i][k] - downMn[i];
                int b = W - up[i][k] - down[i][k];

                int c = up[j][L-1-k] - upMn[j];
                int d = W - up[j][L-1-k] - down[j][L-1-k];
                
                if(a == c && b == d) cnt++;
                //cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
            }
            if(cnt == L) flag = true;

            if(flag){ 
                ret--;
                break;
            }
        }
    }

    cout << ret;
}
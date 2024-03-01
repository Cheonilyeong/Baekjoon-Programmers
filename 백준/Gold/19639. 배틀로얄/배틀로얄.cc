#include <bits/stdc++.h>
using namespace std;

int X, Y, M, n, hp;
bool flag = true;
queue<pair<int,int>> damage;
queue<pair<int,int>> healing;
vector<int> ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> X >> Y >> M;

    for(int i = 1; i <= X; i++) {
        cin >> n;
        if(n >= M/2) damage.push({i,M/2});
        if(n < M/2)  damage.push({i,n});
    }

    for(int i = 1; i <= Y; i++) {
        cin >> n;
        if(n >= M/2) healing.push({i,M/2});
        if(n < M/2)  healing.push({i,n});
    }

    hp = M;

    while(damage.size() || healing.size()) {

        if(hp > M/2) {

            if(damage.size()) {
                hp -= damage.front().second;
                ret.push_back(damage.front().first*-1);
                damage.pop();
            }
            else {
                hp += healing.front().second;
                ret.push_back(healing.front().first);
                healing.pop();
            }
        }
        else if(hp <= M/2) {
            
            if(healing.size()) {
                hp += healing.front().second;
                ret.push_back(healing.front().first);
                healing.pop();
            }
            else {
                hp -= damage.front().second;
                ret.push_back(damage.front().first*-1);
                damage.pop();
            }
        }
        
        if(hp > M) hp = M;
        if(hp <= 0) {flag = false; break;}

    }

    if(flag) {
        for(int i : ret) {
            cout << i << '\n';
        }
    }
    else cout << 0 << '\n';
}
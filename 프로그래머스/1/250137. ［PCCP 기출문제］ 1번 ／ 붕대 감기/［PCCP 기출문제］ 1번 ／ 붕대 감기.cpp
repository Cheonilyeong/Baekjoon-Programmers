#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    queue<pair<int,int>> q;
    
    // 공격 저장
    for(vector<int> v : attacks) {
        q.push({v[0], v[1]});
    }
    
    int T = 1;
    int B = 0;
    int hp = health;
    
    while(1) {
        // 더이상 공격 안하면
        if(q.empty()) return hp;
        // 공격하면
        else if(T == q.front().first) {
            hp -= q.front().second;
            q.pop();
            T++;
            B = 0;
            if(hp <= 0) return -1;
        }
        // 공격 안하면
        else if(T != q.front().first) {
            if(B + 1 == bandage[0]) {
                hp = hp + bandage[1] + bandage[2];
                hp = min(health, hp);
                B = 0;
            }
            else {
                hp = hp + bandage[1];
                hp = min(health, hp);
                B++;
            }
            T++;
        }
    }
    
    return hp;
}
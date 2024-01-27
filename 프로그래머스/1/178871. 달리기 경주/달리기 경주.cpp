#include <bits/stdc++.h>

using namespace std;

map<string,int> mp; // 선수, 순위
vector<string> ranking; // 결과

vector<string> solution(vector<string> players, vector<string> callings) {
    
    // 순서 저장
    for(int i = 0; i<players.size(); i++) {
        mp.insert({players[i], i}); 
        ranking.push_back(players[i]);
    }
    
    for(string s : callings) {
        // A가 B를 추월
        string A, B;
        int rankA, rankB;
        
        A = s; 
        B = ranking[mp[A] - 1];
        rankA = mp[A];
        rankB = rankA - 1;
        
        swap(mp[A], mp[B]);
        swap(ranking[rankA], ranking[rankB]);
    }
    
    return ranking;
}
#include <bits/stdc++.h>

using namespace std;

// A가 B에게 준 선물 개수
int cnt[54][54];
// A가 보낸 선물과 받은 선물 개수
map<int,pair<int,int>> mp;

int solution(vector<string> friends, vector<string> gifts) {
    vector<int> ret(friends.size());
    
    // 선물 계산
    for(string s : gifts) {
        int pos = s.find(" ");
        string A = s.substr(0, pos);
        string B = s.substr(pos+1);
        int idxA, idxB;
        for(int i = 0; i<friends.size(); i++) {
            if(A == friends[i]) idxA = i;
            if(B == friends[i]) idxB = i;
        }
        cnt[idxA][idxB]++;
        mp[idxA].first++;
        mp[idxB].second++;
    }
    
    // 다음 달 선물 계산
    for(int i = 0; i<friends.size()-1; i++) {
        for(int j = i+1; j<friends.size(); j++) {
            if(cnt[i][j] > cnt[j][i]) ret[i]++;
            else if(cnt[i][j] < cnt[j][i]) ret[j]++;
            else if(cnt[i][j] == cnt[j][i]) {
                int giftA = mp[i].first-mp[i].second;
                int giftB = mp[j].first-mp[j].second;
                if(giftA > giftB) ret[i]++;
                else if(giftA < giftB) ret[j]++;
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    
    return ret.back();
}
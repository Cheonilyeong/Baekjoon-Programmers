#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    int N = photo.size();
    vector<int> answer(N,0);
    map<string,int> mp;     // <name,yearning>
    
    // 그리움 점수 저장
    for(int i = 0; i < name.size(); i++) {
        mp[name[i]] = yearning[i];
    }
    
    // 각 사진별 그리움 점수 계산
    for(int i = 0; i < N; i++) {
        for(string s : photo[i]) {
            answer[i] += mp[s];
        }
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

set<string> st;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for(int i = 0; i<words.size(); i++) {
        // 단어가 이어지지 않으면
        if(i != 0 && words[i-1].back() != words[i].front()) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        // 처음 말한 단어면
        if(st.find(words[i]) == st.end()) {
            st.insert(words[i]);
        }
        // 이미 말한 단어면
        else {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
    }
    
    if(!answer.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
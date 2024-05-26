#include <bits/stdc++.h>
using namespace std;

int N;
string s;
map<string,int> mp;

vector<string> split(string input, string delimeter) {
    vector<string> result;

    int pos;
    while((pos = input.find(delimeter)) != string::npos) {
        string t = input.substr(0, pos+delimeter.size()-1);
        if(t != "-") result.push_back(t);
        input.erase(0, pos+delimeter.size());
    }
    if(input != "-") result.push_back(input);

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    getline(cin, s);
    while(N--) {

        for(int i = 0; i < 4; i++) {
            // 근무 시간표 받기
            getline(cin, s);

            // split
            vector<string> v;
            v = split(s, " ");

            // 근무 시간 더하기
            for(string a : v) {
                if(i == 0) mp[a] += 4;
                if(i == 1) mp[a] += 6;
                if(i == 2) mp[a] += 4;
                if(i == 3) mp[a] += 10;
            }
        }
    }

    vector<int> ret;
    for(auto it : mp) {
        ret.push_back(it.second);
    }

    // 공평?
    bool flag = true;
    for(int i = 0; i < ret.size(); i++) {
        for(int j = i+1; j < ret.size(); j++) {
            if(abs(ret[i] - ret[j]) > 12) flag = false; 
        }
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
}
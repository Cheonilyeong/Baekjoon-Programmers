#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string filename;
    string extension;
}file;

int N, M, pos;
string s;
vector<file> v;
set<string> st;

bool comp(const file& a, const file& b) {
    // 파일명이 같다면
    if(a.filename == b.filename) {
        // 인식하는 확장자가 아니라면
        if(st.find(a.extension) == st.end() && st.find(b.extension) == st.end()) {
            return a.extension < b.extension;
        }
        // 인식하는 확장자라면
        else if(st.find(a.extension) != st.end() && st.find(b.extension) != st.end()) {
            return a.extension < b.extension;
        }
        // a만 인식하는 확장자라면
        else if(st.find(a.extension) != st.end()) return true;
        // b만 인식하는 확장자라면
        else return false;
    }
    // 파일명이 다르면
    else {
        return a.filename < b.filename;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    while(N--) {
        cin >> s;
        pos = s.find('.');
        file f;
        f.filename = s.substr(0,pos);
        f.extension = s.substr(pos+1);
        v.push_back(f);
    }

    while(M--) {
        cin >> s;
        st.insert(s);
    }

    sort(v.begin(), v.end(), comp);

    for(file f : v) {
        cout << f.filename << '.' << f.extension << '\n';
    }
}
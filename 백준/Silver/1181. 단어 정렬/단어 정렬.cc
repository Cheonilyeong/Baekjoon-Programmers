#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> v;
set<string> st;

bool compare(string &a, string &b) {
    if(a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;
        if(st.find(s) == st.end()) {
            v.push_back(s);
            st.insert(s);
        }
    }

    sort(v.begin(), v.end(), compare);

    for(string s : v) {
        cout << s << '\n';
    }

}
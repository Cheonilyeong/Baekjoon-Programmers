#include <bits/stdc++.h>
using namespace std;

int T, m, num;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    // 테스트케이스
    while(T--) {
        cin >> m;

        int cnt = 0;
        set<int> st;
        set<pair<int,int>> left;
        vector<int> v;
        // 왼쪽
        for(int i = 0; i < m; i++) {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for(int i : v) {
            if(st.find(i) == st.end()) {
                st.insert(i);
                st.insert(i+500);
                left.insert({i,i+500});
            }
            else continue;
        }

        st.clear();
        // v.clear();
        vector<int> v2;
        // 오른쪽
        for(int i = 0; i < m; i++) {
            cin >> num;
            v2.push_back(num);
        }
        sort(v2.begin(), v2.end());
        for(int i : v2) {
            if(st.find(i) == st.end()) {
                st.insert(i);
                st.insert(i+500);
                // 왼쪽에서 오는 차량
                if(left.find({i-1000, i-500}) != left.end()) {
                    cnt++;
                }
            }
            else continue;
        }

        cout << cnt << '\n';
    }
}
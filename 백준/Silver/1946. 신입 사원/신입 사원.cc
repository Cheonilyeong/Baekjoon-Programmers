#include <bits/stdc++.h>
using namespace std;

int T, N, a, b;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--) {
        int minB = INT_MAX, cnt=0;
        vector<pair<int,int>> v;

        cin >> N;

        while(N--) {
            cin >> a >> b;
            v.push_back({a,b});
        }

        sort(v.begin(), v.end(), less<pair<int,int>>());
        // 서류 1 2 3 4 5
        // 면접 4 3 2 1 5
        // 순회하면서 본인 앞에 있는 사람보다 면접 순위가 낮으면 탈락이다.
        // (이미 앞에 있는 사람보다 서류 순위가 낮기 때문에)
        // 가장 높은 순위를 저장해놓아 시간복잡도를 줄일 수 있다. n2 -> n
        for(auto it : v) {
            if(it.second < minB) cnt++;
            minB = min(minB, it.second);
        }

        cout << cnt << '\n';
    }
}
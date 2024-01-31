#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> graph[12];

int main(void) {

    for(int i = 0; i < 12; i++) {
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for(vector<int> g : graph) {
        // 예제 그림 1 or 5 or 6 or 12
        if(g.size() == 1) {
            // 7 or 4
            if(graph[g[0]].size() == 3) {
                // 7과 4가 연결되어있는 별 확인
                for(int i : graph[g[0]]) {
                    // 7에는 연결된 별이 2개인 8이 있다.
                    if(graph[i].size() == 2) {
                        cout << g[0] + 1;
                    }
                }
            }
        }
    }

}
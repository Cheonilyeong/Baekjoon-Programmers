#include <bits/stdc++.h>

using namespace std;

int N, M, sum, y, x, mn=INT_MAX, mp[54][54], visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int,int>> v;
vector<int> np;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 2) v.push_back({i,j});
        }
    }

    for(int i = 0; i < v.size()-M; i++) np.push_back(0);
    for(int i = 0; i < M; i++) np.push_back(1);

    do {
        sum = 0;

        for(int i = 0; i < v.size(); i++) {
            if(np[i] == 1) {
                queue<pair<int,int>> q;
                q.push({v[i].first,v[i].second});
                visited[v[i].first][v[i].second] = 1;

                while(q.size()) {
                    tie(y,x) = q.front(); q.pop();

                    for(int i = 0; i<4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny < 0 || ny >= N || nx < 0 || nx >= N)  continue;
                        if(visited[ny][nx] == 0 || visited[ny][nx] > visited[y][x] + 1) {
                            visited[ny][nx] = visited[y][x] + 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }


        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                if(mp[i][j] == 1)
                    sum += (visited[i][j]-1);
            }
        }
        mn = min(mn,sum);
        memset(visited, 0, sizeof(visited));

    } while(next_permutation(np.begin(), np.end()));

    cout << mn;
}
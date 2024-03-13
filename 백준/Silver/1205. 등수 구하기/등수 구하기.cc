#include <bits/stdc++.h>
using namespace std;

int N, P, T, l, r, m;
bool flag = true;
vector<int> score;
vector<int> ranking;
vector<int> newRanking;


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> T >> P;

    score.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> score[i];
    }

    sort(score.begin(), score.end(), greater<int>());
    for(int i = 0; i < N; i++) {
        if(i >= P) break;
        ranking.push_back(score[i]);
    }

    score.push_back(T);
    sort(score.begin(), score.end(), greater<int>());
    if(N == 0) newRanking.push_back(T);
    for(int i = 0; i < N+1; i++) {
        if(i >= P) break;
        newRanking.push_back(score[i]);
    }

    
    if(ranking == newRanking) cout << -1;
    else {
        for(int i = 0; i < P; i++) {
            if(newRanking[i] == T) {
                cout << i + 1;
                flag = false;
                break;
            }
        }
        if(flag) cout << -1;
    }

}
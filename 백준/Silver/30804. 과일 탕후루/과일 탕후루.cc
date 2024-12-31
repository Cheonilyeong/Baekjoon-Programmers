#include <bits/stdc++.h>

using namespace std;

int N, mx = INT_MIN;
int arr[200004];

int main() {
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < 9; i++) {
        for(int j = i+1; j <= 9; j++) {
            
            int cnt = 0;
            for(int idx = 0; idx < N; idx++) {
                if(arr[idx] == i || arr[idx] == j) {
                    cnt++;
                    mx = max(cnt, mx);
                } else {
                    cnt = 0;
                    mx = max(cnt, mx);
                }
            }
        }
    }

    cout << mx;
}
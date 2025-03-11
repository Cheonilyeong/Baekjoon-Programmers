#include <bits/stdc++.h>
using namespace std;

int N, K, num, eat, meal = 2;
int As, Ae, Bs, Be, Cs, Ce;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    cin >> As >> Ae >> Bs >> Be >> Cs >> Ce;

    eat = Ae;
    while(N) {
        if(meal == 1) {
            if(eat + K - 1440 < As) break; 
            else if(eat + K - 1440 >= As && eat + K - 1440 <= Ae) eat = eat + K - 1440;
            else if(eat + K - 1440 > Ae) eat = Ae;
            meal++;
            continue;
        }
        
        if(meal == 2) {
            if(eat + K < Bs) break;
            else if(eat + K >= Bs && eat + K <= Be) eat += K;
            else if(eat + K > Be) eat = Be;
            meal++;
            continue;
        }
        
        if(meal == 3) {
            if(eat + K < Cs) break;
            else if(eat + K >= Cs && eat + K <= Ce) eat += K;
            else if(eat + K > Ce) eat = Ce;
            N--;
            meal = 1;
            continue;
        }
    }

    if(N) cout << "NO"; else cout << "YES";
}
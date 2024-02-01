#include <bits/stdc++.h>
using namespace std;

int A, B, C, a;
long long costA, costB, cntC;
bool flag = true;
string s;
map<string,int> mpA;
map<string,int> mpB;
set<string> mpC;

int main(void) {

    cin >> A >> B >> C;

    while(A--) {
        cin >> s >> a;
        mpA[s] = a;
    }
    while(B--) {
        cin >> s >> a;
        mpB[s] = a;
    }
    while(C--) {
        cin >> s;
        mpC.insert(s);
    }

    cin >> a;
    while(a--) {
        cin >> s;
        if(mpA.find(s) != mpA.end()) {
            costA += mpA[s];
        }
        else if(mpB.find(s) != mpB.end()) {
            costB += mpB[s];
        }
        else if(mpC.find(s) != mpC.end()) {
            cntC++;
        }
    }

    if((costA < 20000 && costB > 0) || (costA + costB < 50000 && cntC) || (cntC > 1)) cout << "No";
    else cout << "Okay";
    
}
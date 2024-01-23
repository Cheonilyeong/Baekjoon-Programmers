#include <bits/stdc++.h>

using namespace std;

double b, sum, cnt;
string a, c;

int main(void) {
    for(int i = 0; i < 20; i++) {
        cin >> a >> b >> c;
        if(c == "A+") {
            sum += b * 4.5;
            cnt += b;
        }
        else if(c == "A0") {
            sum += b * 4.0;
            cnt += b;
        }
        else if(c == "B+") {
            sum += b * 3.5;
            cnt += b;
        }
        else if(c == "B0") {
            sum += b * 3.0;
            cnt += b;
        }
        else if(c == "C+") {
            sum += b * 2.5;
            cnt += b;
        }
        else if(c == "C0") {
            sum += b * 2.0;
            cnt += b;
        }
        else if(c == "D+") {
            sum += b * 1.5;
            cnt += b;
        }
        else if(c == "D0") {
            sum += b * 1.0;
            cnt += b;
        }
        else if(c == "F") {
            sum += b * 0;
            cnt += b;
        }
    }
    cout << fixed << setprecision(6) << sum / cnt;  // 소수점 6자리까지 나타내기
}
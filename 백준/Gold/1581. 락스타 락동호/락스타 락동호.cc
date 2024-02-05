#include <bits/stdc++.h>
using namespace std;

int FF, FS, SF, SS, ret;

int main(void) {

    cin >> FF >> FS >> SF >> SS;


    if(FF == 0) {

        if(FS != 0) {
            if(FS > SF) {
                ret += SF*2 + 1;
            }
            else if(FS < SF) {
                ret += FS*2;
            }
            else if(FS == SF) {
                ret += (FS-1)*2 + 1;
            }
            ret += SS;
        }
        else {
            ret += SS;
            if(SF > 0) ret += 1;
        }
    }
    else {
        ret += FF;

        if(FS != 0) {
            if(FS > SF) {
                ret += SF*2 + 1;
            }
            else if(FS < SF) {
                ret += FS*2 - 1;
                ret += 1;
            }
            else if(FS == SF) {
                ret += FS*2;
            }
            ret += SS;
        }
    }

    cout << ret;
}
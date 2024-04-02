#include <iostream>
using namespace std;

int a, b;

int main(void) {

    while(cin >> a >> b) {
        if(a == 0 && b ==0) break;
        cout << ((a > b) ? "Yes\n" : "No\n");
    }
}
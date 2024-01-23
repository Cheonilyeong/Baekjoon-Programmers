#include <bits/stdc++.h>

using namespace std;

int a;

int main(void) {
    cin >> a;
    int s = 1;
    for(int i = 1; i < a; i++) {
        for(int j = 0; j < a - i; j++) cout << ' ';
        for(int j = 0; j < i - 1; j++) cout << '*';
        cout << '*';
        for(int j = 0; j < i - 1; j++) cout << '*';
        //for(int j = 0; j < a - i; j++) cout << ' ';
        cout << '\n';
    } 
    for(int i = 0; i < (1 + 2 * (a - 1)); i++) cout << '*';
    cout << '\n';
    for(int i = a - 1; i > 0; i--) {
        for(int j = 0; j < a - i; j++) cout << ' ';
        for(int j = 0; j < i - 1; j++) cout << '*';
        cout << '*';
        for(int j = 0; j < i - 1; j++) cout << '*';
        //for(int j = 0; j < a - i; j++) cout << ' ';
        cout << '\n';
    } 
}
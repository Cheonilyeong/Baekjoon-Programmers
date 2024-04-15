#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(){
    stack<char> vps;
    int count;
    cin >> count;
    char str[50];
    int print[count];
    for(int i = 0; i < count; i++){
        scanf("%s", str);
        while(!vps.empty())
            vps.pop();
        for(char a : str){
            //cout << a;
            if(a == '(')
                vps.push(a);
            else if(a == ')'){
                if(!vps.empty() && vps.top() == '(')
                    vps.pop();
                else
                    vps.push(a);
            }
        }
        if(vps.empty())
            print[i] = 1;
        else
            print[i] = 0;
        fill(&str[0], &str[50], '\0');
        //cout << '\n';
    }


    for(int a : print){
        if(a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
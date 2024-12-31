#include <bits/stdc++.h>
using namespace std;

struct node {
    int value = 0;
    node* left = NULL;
    node* right = NULL;
};

int num;
vector<int> v;
node root;

void go(int num, node& now) {
    if(now.value == 0) {
        now.value = num;
        return;
    }
    else if(num < now.value) {
        if(now.left == NULL) {
            now.left = (node*)malloc(sizeof(node));
            now.left->value = num;
            now.left->left = NULL;
            now.left->right = NULL;
            return;
        }
        else {
            go(num, *now.left);
        }
    }
    else if(num > now.value) {
        if(now.right == NULL) {
            now.right = (node*)malloc(sizeof(node));
            now.right->value = num;
            now.right->left = NULL;
            now.right->right = NULL;
            return;
        }
        else {
            go(num, *now.right);
        }
    }
}

void lrm(node& now) {
    if(now.left != NULL) lrm(*now.left);
    if(now.right != NULL) lrm(*now.right);
    cout << now.value << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(cin >> num) {
        go(num, root);
    }

    lrm(root);
}
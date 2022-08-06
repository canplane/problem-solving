#include <iostream>
#include <utility>
using namespace std;

int N;
pair<char, char> tree[26];

void preorder(int parent) {
    if (parent == '.')
        return;
    printf("%c", parent);
    preorder(tree[parent - 'A'].first);
    preorder(tree[parent - 'A'].second);
}
void inorder(int parent) {
    if (parent == '.')
        return;
    inorder(tree[parent - 'A'].first);
    printf("%c", parent);
    inorder(tree[parent - 'A'].second);
}
void postorder(int parent) {
    if (parent == '.')
        return;
    postorder(tree[parent - 'A'].first);
    postorder(tree[parent - 'A'].second);
    printf("%c", parent);
}

int main() {
    cin >> N;
    char parent, l, r;
    for (int i = 0; i < N; i++) {
        cin >> parent >> l >> r;
        tree[parent - 'A'] = { l, r };
    }
    preorder('A'), cout << endl;
    inorder('A'), cout << endl;
    postorder('A'), cout << endl;
}
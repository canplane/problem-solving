#include <cstdio>

int N;
struct { char l, r; } node[26];

void preorder(char c) {
    if (c == '.') return;
    printf("%c", c);
    preorder(node[c - 'A'].l);
    preorder(node[c - 'A'].r);
}
void inorder(char c) {
    if (c == '.') return;
    inorder(node[c - 'A'].l);
    printf("%c", c);
    inorder(node[c - 'A'].r);
}
void postorder(char c) {
    if (c == '.') return;
    postorder(node[c - 'A'].l);
    postorder(node[c - 'A'].r);
    printf("%c", c);
}

int main() {
    scanf("%d", &N);

    char parent, l, r;
    for (int i = 0; i < N; i++) {
        scanf(" %c %c %c", &parent, &l, &r);
        node[parent - 'A'].l = l;
        node[parent - 'A'].r = r;
    }
    
    preorder('A'), puts("");
    inorder('A'), puts("");
    postorder('A'), puts("");
}
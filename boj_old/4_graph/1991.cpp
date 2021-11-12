#include <cstdio>
#include <utility>

std::pair<char, char> tree[26];

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
    int N;
    char root;
    char parent, l, r;
    scanf("%d", &N);

    root = '\0';    
    while (N--) {
        scanf(" %c %c %c", &parent, &l, &r);  // %c 앞에 공백 두면 공백 문자 무시!
        //printf("'%c', '%c', '%c'\n", parent, l, r);
        if (!root)
            root = parent;
        tree[parent - 'A'].first = l;
        tree[parent - 'A'].second = r;
    }
    
    preorder(root), puts("");
    inorder(root), puts("");
    postorder(root), puts("");
}
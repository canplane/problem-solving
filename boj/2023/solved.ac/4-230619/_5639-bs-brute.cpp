using namespace std;
#include <cstdio>

struct Node {
	int e;
	Node *l, *r;
	Node(int _e) { e = _e; l = r = NULL; }
};
Node *root = NULL;

void insert(Node **node, int e)
{
	if (!*node) {
		*node = new Node(e);
		return;
	}
	if (e < (*node)->e)
		insert(&(*node)->l, e);
	else
		insert(&(*node)->r, e);
}
void postorder(Node *node)
{
	if (!node) {
		return;
	}
	postorder(node->l);
	postorder(node->r);
	printf("%d\n", node->e);
}

int main()
{
	int e;
	while (scanf("%d", &e) != -1) {
		insert(&root, e);
	}
	postorder(root);
}
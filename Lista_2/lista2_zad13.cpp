#include <iostream>
#include <stack>

struct Node {
	Node(double v = 0, Node* p = NULL) : value(v), parent(p) {}

	Node* left = NULL;
	Node* right = NULL;
	Node* parent = NULL;
	double value;
};

void insert(Node *root, double v) {
	Node **n = &root;
	Node *p = NULL;

	while (*n) {
		p = *n;
		if (v == (*n)->value)
			return;
		if (v < (*n)->value) {
			n = &(*n)->left;
		}
		else {
			n = &(*n)->right;
		}
	}

	*n = new Node(v, p);
}

// zadanie 13
void inorder_do(Node * t, void f(Node* x)) {
	if (t != NULL){
		inorder_do(t->left, f);
		f(t);
		inorder_do(t->right, f);
	}
}

int main() {
	Node *root = new Node(0);
	double values[] = { 2, 5, 13, 25, -2, -6, 9, 8, 22 };
	for (int i = 0; i<9; i++) {
		insert(root, values[i]);
	}

	inorder_do(root, [](Node* x) { std::cout<< x->value << " " <<std::endl; });

	return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class BTnode {
  public:
	int value;
	BTnode *left;
	BTnode *right;
	BTnode *parent;
	 
	BTnode(int val, BTnode *leftSide, BTnode *rightSide, BTnode *newParent) {
		 value = val;
		 left = leftSide;
		 right = rightSide;
		 parent = newParent;
	}
};

int depth(BTnode node, BTnode root) {
	int depth = 0;
	while (node.value != root.value) {
		node = *node.parent;
		depth++;
	}
	return depth;
}

int size(BTnode *node) {
	if (!node) { return 0; }
	return 1 + size(node->left) + size(node->right);
}

//add node to binary tree
void insert(BTnode* node, BTnode* root) {
	BTnode	*nxt = root;
	while (nxt != NULL) {
		if (node->value > nxt->value) {
			if (nxt->right) {
				nxt = nxt->right;
			}
			else {
				nxt->right = node;
				break; 
			}
		}
		else { 
			if (nxt->left) {
				 nxt = nxt->left; 
			}
			else {
				nxt->left = node;
				break; 
			}
		}
	}
		node->parent = nxt;
}
//basic binary tree traversal
void traverse(BTnode* root) {
	BTnode* prev = NULL;
	BTnode* node = root;
	BTnode* nxt;
	while (node != NULL) {
		if (prev == node->parent) {
			if (node->left) {
				nxt = node->left;
			}
			else if (node->right) {
				nxt = node->right;
			}
			else { nxt = node->parent; }
		}
		else if (prev == node->left) {
			if (node->right) {
				nxt = node->right;
			}
			else { nxt = node->parent; }
		}
		else { nxt = node->parent; }
		prev = node;
		node = nxt;
	}

}

int main() {
	BTnode r(5, NULL, NULL, NULL);
	BTnode n1(2, NULL, NULL, NULL);
	BTnode n2(1, NULL, NULL, NULL);
	BTnode n3(3, NULL, NULL, NULL);
	BTnode n4(4, NULL, NULL, NULL);
	BTnode n5(8, NULL, NULL, NULL);
	BTnode n6(7, NULL, NULL, NULL);
	BTnode n7(10, NULL, NULL, NULL);
	BTnode n8(9, NULL, NULL, NULL);
	insert(&n1, &r);
	insert(&n2, &r);
	insert(&n3, &r);
	insert(&n4, &r);
	insert(&n5, &r);
	insert(&n6, &r);
	insert(&n7, &r);
	insert(&n8, &r);

	traverse(&r);


}
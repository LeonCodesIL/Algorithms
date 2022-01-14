#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class BTnode {
  public:
	string value;
	BTnode *left;
	BTnode *right;
	BTnode *parent;
	 
	BTnode(string val, BTnode *leftSide, BTnode *rightSide, BTnode *newParent) {
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


int treverse(BTnode* root) {
	BTnode* prev = root;

	

}

int main() {
	BTnode r(NULL, NULL, NULL, NULL);
	BTnode m("2", NULL, NULL, &r);
	BTnode k("3", NULL, NULL, &m);


	r.left = &m;
	m.right = &k;


}
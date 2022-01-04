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

	BTnode(string val, BTnode *leftSide, BTnode* rightSide, BTnode* newParent) {
		 value = val;
		 left = leftSide;
		 right = rightSide;
		 parent = newParent;
	}
};
//code not working, figure out if its possible to assaign one object to another like in javascript
int main() {
	BTnode r("first", NULL, NULL, NULL);
	BTnode m("1", NULL, NULL, &r);
	r.left = &m;
	std::cout << &r << endl;
	std::cout << m.parent << endl;
	int depth = 0;
	
	while (&m != &r) {
		m = *m.parent;
		depth++;
	}
	std::cout << &r << endl;
	std::cout << &m << endl;
}
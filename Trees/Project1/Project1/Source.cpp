#include <iostream>

using namespace std;
int main()
{
	BTnode r("first", NULL, NULL, NULL);
	printf("%s", r.value);
}


class BTnode {
  public:
	string value;
	BTnode *left;
	BTnode *right;
	BTnode *parent;

	BTnode(string val, BTnode* leftSide, BTnode* rightSide, BTnode* newParent) {
		 value = val;
		 left = leftSide;
		 right = rightSide;
		 parent = newParent;
	}
};

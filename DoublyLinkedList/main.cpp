#include <iostream>
#include "DLList.h"

using namespace std;

int main() {

	DLList<int> *list(0);
	list = new DLList<int>;

	list->appendNode(3);
	list->appendNode(4);
	list->appendNode(5);
	list->deleteNodeByValue(4);
	list->prependNode(6);
	list->displayDLList();

	return 0;
}

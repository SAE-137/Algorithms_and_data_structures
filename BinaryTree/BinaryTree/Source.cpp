#include<iostream>
#include"BinaryTree.h"

int main()
{


	BinaryTree a;
	for (int i = 0; i < 20; i++)
		a.addNode(rand() % 100);
	a.printTree(a.getRoot(), nullptr, false);
	

	BinaryTree b;
	b.copyTree(a.getRoot()->left);

	
	
	b.printTree(b.getRoot(), nullptr, false);
	return 0;
}
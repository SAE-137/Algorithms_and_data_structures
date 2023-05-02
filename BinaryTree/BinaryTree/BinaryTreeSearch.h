#include "BinaryTree.h"
#pragma once




class BinaryTreeSearch : public BinaryTree
{


	int foo(int k);
	BinaryTreeSearch();
	~BinaryTreeSearch(); 


	int maxKey(Node* node);
	int minKey(Node* node);
	void addNode(int data) override;
	BinaryTree::Node* crossingTree(Node* node);
	int nodeLevel(int key);
	Node* search(int key);
	Node* deleteNode(Node* root, int key)override;
	Node* copy(Node* node);
	BinaryTreeSearch* copyTree(Node* node);
	void destroy_tree(Node* leaf);
	void setRoot(Node* newroot);
	//BinaryTreeSearch& operator=(const BinaryTreeSearch& obj);
	
};


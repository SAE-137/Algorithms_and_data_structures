#pragma once

#include"Node.h"
#include "BinaryTree.h"

class BinaryTreeSearch : BinaryTree
{
	BinaryTreeSearch();
	~BinaryTreeSearch(); // дописать 

	void addNode(int data) override;
	void destroy_tree(Node* leaf);

	int maxKey(Node* node) override;
	int minKey(Node* node) override;
	int nodeLevel(int key) override;

	Node* crossingTree(Node* node); //переписать
	Node* copy(Node* node) override; 
	Node* search(int key) override;
	Node* deleteNode(Node* root, int key) override;

	BinaryTreeSearch* copyTree(Node* node); 
	BinaryTreeSearch& operator=(const BinaryTreeSearch& obj) //дописать;
};


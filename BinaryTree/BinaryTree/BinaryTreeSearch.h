#pragma once

#include"Node.h"
#include "BinaryTree.h"

class BinaryTreeSearch : BinaryTree
{
	BinaryTreeSearch();
	~BinaryTreeSearch(); // дописать 

	void addNode(int data) override;
	Node* deleteNode(Node* root, int key) override; // дописать 


	Node* copy(Node* node) override; // дописать
	Node* search(int key) override;

	BinaryTreeSearch* copyTree(Node* node); // дописать 
};


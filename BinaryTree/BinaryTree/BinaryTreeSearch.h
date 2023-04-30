#pragma once

#include"Node.h"
#include "BinaryTree.h"

class BinaryTreeSearch : BinaryTree
{
	BinaryTreeSearch();
	~BinaryTreeSearch(); // �������� 

	void addNode(int data) override;
	Node* deleteNode(Node* root, int key) override; // �������� 


	Node* copy(Node* node) override; // ��������
	Node* search(int key) override;

	BinaryTreeSearch* copyTree(Node* node); // �������� 
};


#pragma once

#include"Node.h"
#include "BinaryTree.h"

class BinaryTreeSearch : BinaryTree
{
	BinaryTreeSearch();
	~BinaryTreeSearch(); // �������� 

	void addNode(int data) override;
	void deleteNode(int key) override; // �������� 


	Node* copy(Node* node) override; // ��������
	Node* search(int key) override;

	BinaryTreeSearch* copyTree(Node* node); // �������� 
};


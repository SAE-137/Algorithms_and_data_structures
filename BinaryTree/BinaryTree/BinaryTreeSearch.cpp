#include "BinaryTreeSearch.h"
#include"Node.h"
#include "BinaryTree.h"

BinaryTreeSearch::BinaryTreeSearch()
{

}

BinaryTreeSearch::~BinaryTreeSearch()
{

}



void BinaryTreeSearch::addNode(int data)
{
	Node* newNode = new Node(data);
	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* focusNode = root;
		Node* parent;
		while (true) {
			parent = focusNode;

			if (data < focusNode->m_key) {
				focusNode = focusNode->left;
				if (focusNode == nullptr) {
					parent->left = newNode;
					newNode->parent = parent;
					return;
				}
			}
			else {
				focusNode = focusNode->right;
				if (focusNode == nullptr) {
					parent->right = newNode;
					newNode->parent = parent;
					return;
				}
			}
		}
	}
}

Node* BinaryTreeSearch::copy(Node* node)
{

}

BinaryTreeSearch* BinaryTreeSearch::copyTree(Node* node)
{

}

Node* BinaryTreeSearch::deleteNode(Node* root, int key)
{
	if (root)
		if (key < root->m_key) root->left = deleteNode(root->left, key);     
		else if (key > root->m_key) root->right = deleteNode(root->right, key);
		else {
			if (!root->left && !root->right) return nullptr;          
			if (!root->left || !root->right)
				return root->left ? root->left : root->right;   
																
			Node* newNode = root->left;                       
			while (newNode->right != NULL) newNode = newNode->right;
			root->m_key = newNode->m_key;
			root->left = deleteNode(root->left, newNode->m_key);
		}
	return root;
}


Node* BinaryTreeSearch::search(int key)
{
	if (this->root != nullptr)
	{
		if (key == this->root->m_key)
			return root;
		if (key < root->m_key)
			this->root->left = search(key);
		else
			this->root->right = search(key);
	}
	else return nullptr;
}


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

void BinaryTreeSearch::deleteNode(int key)
{

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
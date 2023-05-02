#include "BinaryTreeSearch.h"
#include "BinaryTree.h"


int BinaryTreeSearch::foo(int k)
{
	BinaryTreeSearch* fvjn;
	Node* node = new Node;
	return k;
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


int BinaryTreeSearch::maxKey(Node* node)
{
	if (node)
	{
		for (node; node != nullptr; node = node->getRightChild()) return node->getKey();
	}
}

int BinaryTreeSearch::minKey(Node* node)
{
	if (node)
	{
		for (node; node != nullptr; node = node->getLeftChild()) return node->getKey();
	}
}

 BinaryTree::Node * BinaryTreeSearch::crossingTree(Node * node)
{

	if (node == nullptr)
		return nullptr;

	Node* newnode = new Node(node->getKey());
	newnode->left = crossingTree(node->left);
	newnode->right = crossingTree(node->right);

	return newnode;
}

 int BinaryTreeSearch::nodeLevel(int key)
 {
	 int i = 0;
	 if (!search(key))
	 {
		 return i;
	 }
	 Node* newNode = search(key);
	 for (newNode; newNode != root; newNode = newNode->getParent())
	 {
		 i++;
	 }
	 return i + 1;
 }

 BinaryTree::Node* BinaryTreeSearch::search(int key)
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

 BinaryTree::Node* BinaryTreeSearch::deleteNode(Node* root, int key)
 {
	 if (root)
		 if (key < root->m_key) root->left = deleteNode(root->left, key);
		 else if (key > root->m_key) root->right = deleteNode(root->right, key);
		 else {
			 if (!root->left && !root->right) return nullptr;
			 if (!root->left || !root->right)
				 return root->left ? root->left : root->right;

			 Node* newNode = root->left;
			 while (newNode->right != nullptr) newNode = newNode->right;
			 root->m_key = newNode->m_key;
			 root->left = deleteNode(root->left, newNode->m_key);
		 }
	 return root;
 }


BinaryTree::Node* BinaryTreeSearch::copy(Node* node)
{
	if (node == nullptr)
		return nullptr;

	node = new Node(node->m_key);
	node->left = copy(node->left);
	node->right = copy(node->right);

	return node;
}

BinaryTreeSearch* BinaryTreeSearch::copyTree(Node* node)
{
	this->setRoot(crossingTree(node));
	return this;
}

void BinaryTreeSearch::destroy_tree(Node* leaf)
{
	if (leaf != nullptr)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTreeSearch::setRoot(Node* newroot)
{
	this->root = newroot;
}

//BinaryTreeSearch& BinaryTreeSearch::operator=(const BinaryTreeSearch& obj)
//{
//	if (this != &obj)
//	{
//		this->root = copy(obj.root);
//	}
//	this->ultimateSuperMegaFullDestroy();
//	return *this;
//}


//Node
BinaryTreeSearch::Node::Node()
{

	m_key = 0;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	int height = 1;
}

BinaryTreeSearch::Node::Node(int key, Node* left, Node* right, Node* parent)
{
	this->right = right;
	this->parent = parent;
	this->left = left;
	m_key = key;
}

BinaryTreeSearch::Node::Node(int key)
{
	m_key = key;
}


void BinaryTreeSearch::Node::setLeftChild(Node* left)
{
	this->left = left;
	left->parent = this;
}

void BinaryTreeSearch::Node::setRightChild(Node* right)
{
	this->right = right;
	right->parent = this;
}

BinaryTreeSearch::Node* BinaryTreeSearch::Node::getParent()
{
	return this->parent;
}

void BinaryTreeSearch::Node::setParent(Node* parent)
{
	this->parent = parent;

}

BinaryTreeSearch::Node* BinaryTreeSearch::Node::getRightChild()
{
	return this->right;
}

BinaryTreeSearch::Node* BinaryTreeSearch::Node::getLeftChild()
{
	return this->left;
}

void BinaryTreeSearch::Node::setKey(int key)
{
	m_key = key;
}

int BinaryTreeSearch::Node::getKey()
{
	return m_key;
}
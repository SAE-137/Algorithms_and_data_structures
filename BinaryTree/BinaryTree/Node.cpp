#include "Node.h"

Node::Node()
{

	m_key = 0;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

Node::Node(int key, Node* left, Node* right, Node* parent)
{
	this->right = right;
	this->parent = parent;
	this->left = left;
	m_key = key;
}

Node::Node(int key)
{
	m_key = key;
}
Node* Node::getLeftChild()
{
	return this->left;
}

Node* Node::getRightChild()
{
	return this->right;
}

Node* Node::getParent()
{
	return this->parent;
}

void Node::setLeftChild(Node* left)
{
	this->left = left;
}

void Node::setRightChild(Node* right)
{
	this->right = right;
}

void Node::setParent(Node* parent)
{
	this->parent = parent;
	
}

void Node::setKey(int key)
{
	m_key = key;
}

int Node::getKey()
{
	return m_key;
}
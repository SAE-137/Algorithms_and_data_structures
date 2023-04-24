#pragma once
class Node
{
public:
	Node();
	Node(int key, Node* left, Node* right, Node* parent);
	Node(int key);
	~Node() = default;

	int getKey();

	Node* getLeftChild();
	Node* getRightChild();
	Node* getParent();

	void setKey(int key);
	void setLeftChild(Node* left);
	void setRightChild(Node* right);
	void setParent(Node* parent);

	int m_key = 0;
	Node* parent = nullptr;
	Node* right = nullptr;
	Node* left = nullptr;

};







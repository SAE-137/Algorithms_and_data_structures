#pragma once
#include"Node.h"
#include<iostream>
#include <vector>
struct Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}

	Trunk()
	{

	}
};

class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree& obj);
	~BinaryTree();

	virtual void deleteNode(int key);
	virtual void addNode(int data);
	void printTree(Node* root, Trunk* prev, bool isLeft);
	void insert(int key, Node* leaf);
	void insert(int key);
	void destroy_tree(Node* leaf);
	void ultimateSuperMegaFullDestroy();
	void showTrunks(Trunk* p);
	void printLeafs(Node* root);
	void printAllLeafs();
	void setRoot(Node* root);

	//void Copy(Node*& to, const Node* from);
	int heigh(Node* root);
	int maxKey(Node* node);
	int minKey(Node* node);
	int tree_sum(Node* tr);
	int nodeLevel(int key);
	
	bool destroy_tree(int key);
	bool isEmpty();
	bool isLeaf(Node* node);
	bool isBalanced(Node* root);

	virtual Node* search(int key);
	virtual Node* copy(Node* node);
	Node* search(int key, Node* leaf);
	Node* getRoot();
	Node* crossingTree(Node* root);

	BinaryTree* copyTree(Node* node);
	BinaryTree& operator=(const BinaryTree& obj);
	//BinaryTree& operator=(const BinaryTree& obj);

	std::vector<int> treeprint(Node* tree);

protected:
	Node* root = nullptr;
	Trunk trunk;

};

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


	int heigh(Node* root);

	void printTree(Node* root, Trunk* prev, bool isLeft);
	void addNode(int data); // search
	void addNewNode(int data);
	void insert(int key, Node* leaf);
	void insert(int key);
	void destroy_tree(Node* leaf);
	void ultimateSuperMegaFullDestroy();
	void showTrunks(Trunk* p);
	void printLeafs(Node* root);
	void printAllLeafs();
	void deleteNode(int key);
	void setRoot(Node* root);

	//void Copy(Node*& to, const Node* from);
	int maxKey(Node* node);
	int minKey(Node* node);
	int tree_sum(Node* tr);
	int nodeLevel(int key);

	bool destroy_tree(int key);
	bool isEmpty();
	bool isLeaf(Node* node);
	bool isBalanced(Node* root);

	Node* search(int key, Node* leaf);
	Node* search(int key);
	Node* copy(Node* node);
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

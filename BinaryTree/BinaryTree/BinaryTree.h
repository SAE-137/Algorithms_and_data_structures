#pragma once

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
		int height = 1;

		Node* parent = nullptr;
		Node* right = nullptr;
		Node* left = nullptr;


		

	};
	BinaryTree();
	BinaryTree(const BinaryTree& obj);
	~BinaryTree();

	virtual Node* deleteNode(Node* root, int key);
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
	virtual int maxKey(Node* node);
	virtual int minKey(Node* node);
	int tree_sum(Node* tr);
	virtual int nodeLevel(int key);
	
	bool destroy_tree(int key);
	bool isEmpty();
	bool isLeaf(Node* node);
	bool isBalanced(Node* root);

	virtual Node* search(int key);
	virtual Node* copy(Node* node);
	Node* search(int key, Node* leaf);
	Node* getRoot();
	virtual Node* crossingTree(Node* root);

	BinaryTree* copyTree(Node* node);
	BinaryTree& operator=(const BinaryTree& obj);
	//BinaryTree& operator=(const BinaryTree& obj);

	std::vector<int> treeprint(Node* tree);


	Node* root = nullptr;
	Trunk trunk;

};

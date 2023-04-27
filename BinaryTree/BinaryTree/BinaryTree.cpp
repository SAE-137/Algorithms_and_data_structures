#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& obj)
{
	root = copy(obj.root);
}

BinaryTree::~BinaryTree()
{
	this->ultimateSuperMegaFullDestroy();
}



void BinaryTree::addNode(int data)
{
	Node* newNode = new Node(data);
	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* focusNode = root;
		while (true)
		{

			if (focusNode->getLeftChild() == nullptr && focusNode->getRightChild() == nullptr)
			{
				if (rand() % 2) focusNode->setLeftChild(newNode);
				else focusNode->setRightChild(newNode);
				return;
			}

			if (focusNode->getLeftChild() != nullptr && focusNode->getRightChild() == nullptr)
			{
				focusNode->setRightChild(newNode);
				return;
			}

			if (focusNode->getLeftChild() == nullptr && focusNode->getRightChild() != nullptr)
			{
				focusNode->setLeftChild(newNode);
				return;
			}
			if (rand() % 2) focusNode = focusNode->getRightChild();
			else focusNode = focusNode->getLeftChild();
			
		}
	}
	
}

Node* BinaryTree::crossingTree(Node* node)
{
	
	if(node == nullptr)
		return nullptr;

	Node* newnode = new Node(node->getKey());
	newnode->left = crossingTree(node->left);
	newnode->right = crossingTree(node->right);

	return newnode;
}

BinaryTree* BinaryTree::copyTree(Node* node)
{
	this->setRoot(crossingTree(node));
	return this;
}

void BinaryTree::setRoot(Node* newroot)
{
	this->root = newroot;
}

void BinaryTree::deleteNode(int key)
{
	Node* newNode = search(key);
	if (newNode != nullptr)
	{
		if (isLeaf(newNode))
		{
			deleteNode(key);
		}

		else if (newNode->right != nullptr && newNode->left != nullptr)
		{
			Node* leaf = newNode;
			for (leaf; leaf != nullptr;)
				leaf = leaf->right;
			if (leaf->getParent()->right == leaf)
				leaf->getParent()->right = nullptr;
			else leaf->getParent()->left = nullptr;

			if(newNode->getParent()->right = newNode)
				newNode->getParent()->right = leaf;
			else newNode->getParent()->left = leaf;

			leaf->setParent(newNode->getParent());
			leaf->setLeftChild(newNode->getLeftChild());
			leaf->setRightChild(newNode->getRightChild());
		}

		else
		{
			if (newNode->right != nullptr && newNode->left == nullptr)
			{
				newNode->right->setParent(newNode->getParent());

				if (newNode->getParent()->right == newNode)
				{
					newNode->getParent()->right = newNode->right;
				}
				
			}

			else
			{
				newNode->left->setParent(newNode->getParent());

				if (newNode->getParent()->left == newNode)
				{
					newNode->getParent()->left = newNode->left;
				}
				
			}

		}
		delete newNode;
	}
}

Node* BinaryTree::getRoot()
{
	return this->root;
}

void BinaryTree::insert(int key, Node* leaf)
{
	if (key < leaf->m_key)
	{
		if (leaf->left != nullptr)
			insert(key, leaf->left);
		else
		{
			leaf->left = new Node;
			leaf->left->m_key = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key >= leaf->m_key)
	{
		if (leaf->right != nullptr)
			insert(key, leaf->right);
		else
		{
			leaf->right = new Node;
			leaf->right->m_key = key;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

void BinaryTree::insert(int key)
{
	if (root != nullptr)
		insert(key, root);
	else
	{
		root = new Node;
		root->m_key = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

Node* BinaryTree::search(int key, Node* root)
{
	if (root != nullptr)
	{
		if (key == root->m_key)
			return root;
		if (key < root->m_key)
			return search(key, root->left);
		else
			return search(key, root->right);
	}
	else return nullptr;
}

Node* BinaryTree::search(int key)
{
	return search(key, root);
}

void BinaryTree::destroy_tree(Node* leaf)
{
	if (leaf != nullptr)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

bool BinaryTree::destroy_tree(int key)
{
	Node* leaf = search(key);


	if (leaf != nullptr)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}

	if (search(key) == nullptr) return true;
	return false;
}

void BinaryTree::ultimateSuperMegaFullDestroy()
{
	destroy_tree(root);
}

//void BinaryTree::Copy(Node*& to, const Node* from) //Node *copy(const Node *from)
//{
//	if (from)
//	{
//		to = new Node{ from->m_key,from->left,from->right };
//
//		Copy(to->left, from->left);
//		Copy(to->right, from->right);
//	}
//}

//BinaryTree::BinaryTree(const BinaryTree& obj)
//{
//	Copy(root, obj.root); //root = copy(obj.root); // root = obj.copy();
//}

int BinaryTree::heigh(Node* root)
{
	if (root == nullptr) {
		return 0;
	}
	//TODO: store subtrees height
	if (heigh(root->left) > heigh(root->right))
		return heigh(root->left) + 1;
	else
		return heigh(root->right) + 1;

}

bool BinaryTree::isEmpty()
{
	if (root) return true;
	return false;
}

std::vector<int> BinaryTree::treeprint(Node* tree)
{
	std::vector<int> keys;
	if (tree != nullptr) {
		treeprint(tree->left);
		treeprint(tree->right);

		keys.push_back(tree->m_key);
	}

	return keys;
}

int BinaryTree::maxKey(Node* node)
{

	if (node->right != nullptr) {
		return minKey(node->right);
	}
	else {
		return node->m_key;
	}
}

int BinaryTree::minKey(Node* node)
{
	if (node->left != nullptr) {
		return minKey(node->left);
	}
	else {
		return node->m_key;
	}
}

void BinaryTree::showTrunks(Trunk* p)
{
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}

void BinaryTree::printTree(Node* root, Trunk* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	std::string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, true);

	if (!prev) {
		trunk->str = "---";
	}
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else {
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	std::cout << " " << root->m_key << std::endl;

	if (prev) {
		prev->str = prev_str;
	}
	trunk->str = "   |";

	printTree(root->left, trunk, false);
}

int BinaryTree::tree_sum(Node* tr)
{
	int l, r;
	if (tr != nullptr) {
		l = (tr->left != nullptr) ? tree_sum(tr->left) : 0;
		r = (tr->right != nullptr) ? tree_sum(tr->right) : 0;
		return l + r + tr->m_key;
	}

	return 0;
}

int BinaryTree::nodeLevel(int key)
{
	Node* node = search(key);
	int value = 0;
	if (node == nullptr) return -1;
	while (node != root)
	{
		node = node->parent;
		value++;
	}

	return value;
}

bool BinaryTree::isLeaf(Node* node)
{
	if (node->getRightChild() == nullptr && node->getLeftChild() == nullptr)
		return true;
	return false;
}

void BinaryTree::printLeafs(Node* node)
{
	if (!node) return;

	printLeafs(node->left);

	if ((node->left == NULL) && (node->right == NULL))

		std::cout << node->getKey() << " ";

	printLeafs(node->right);
}

Node* BinaryTree::copy(Node* node)
{

	if (node == nullptr)
		return nullptr;

	node = new Node(node->m_key);
	node->left = copy(node->left);
	node->right = copy(node->right);

	return node;
}

void BinaryTree::printAllLeafs()
{
	printLeafs(this->getRoot());
}

bool BinaryTree::isBalanced(Node* root)
{
	int ltree;
	int rtree;
	if (root == nullptr)
		return true;
	ltree = heigh(root->left);
	rtree = heigh(root->right);

	if (abs(ltree - rtree) <= 1 && isBalanced(root->left)
		&& isBalanced(root->right))
		return true;

	return false;
}

BinaryTree& BinaryTree::operator=(const BinaryTree& obj)
{
	if (this != &obj)
	{
		this->root = copy(obj.root);
	}
	this->ultimateSuperMegaFullDestroy();
	return *this;
}
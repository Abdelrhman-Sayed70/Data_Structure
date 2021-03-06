#include<iostream>
using namespace std; 
#include "BST.h"
#include<assert.h>

template<class T> 
Node<T>::Node() {
	right = left = nullptr; 
}

template<class T>
Node<T>::Node(T val) {
	right = left = NULL;
	value = val;
}

template<class T> 
BST<T>::BST() {
	numodnodes = 0;
	root =NULL;
	rightbool = leftbool = false;
}

template<class T> 
bool BST<T>::contains(T val) {
	Node<T>* tmp = findnode(val); 
	if (tmp == NULL) { return false; }
	else {
		return true; 
	}
	/*Node<T>* tmp = root;
	while (tmp!=NULL){
		if (val == tmp->value) {
			return true;
		}
		else if (val < tmp->value) {
			tmp = tmp->left;
		}
		else if (val > tmp->value) {
			tmp = tmp->right;
		}
	}
	return false;*/
}

template<class T> 
Node<T>* BST<T>::findnode(T val) {
	Node<T>* tmp = root;
	while (tmp != NULL) {
		if (val == tmp->value) {
			return tmp;
		}
		else if (val < tmp->value) {
			tmp = tmp->left;
		}
		else if (val > tmp->value) {
			tmp = tmp->right;
		}
	}
	return  NULL;
}

template<class T>
void BST<T>::insert(T val) {
	assert(!contains(val));
	numodnodes++;
	Node<T>* newnode = new Node<T>(val);
	if (root == NULL) {
		root = newnode;
	}
	else {
		Node<T>* tmp = root;
		while (true) {
			if (val < tmp->value) {
				leftbool = true;					
				if (tmp->left == NULL) { tmp->left = newnode; break; }
				else {
					tmp = tmp->left;
				}
			}
			else {
				rightbool = true;
				if (tmp->right == NULL) { tmp->right = newnode; break; }
				else {
					tmp = tmp->right;
				}
			}
		}
	}
}

template<class T>
void BST<T>::traverse(int type) {
	if (type == 1) {
		inorder(root);
	}
	else if (type == 2) {
		preorder(root);
	}
	else {
		postorder(root);
	}
}

template<class T>
void BST<T>::inorder(Node<T>*start) {
	// left , root , right
	if (start != NULL) {
		inorder(start->left);
		cout << start->value << " ";
		inorder(start->right);
	}
}

template<class T>
void BST<T>::preorder(Node<T>* start) {
	// root left right 
	if (start != NULL) {
		cout << start->value << " ";
		preorder(start->left);
		preorder(start->right);
	}
}

template<class T>
void BST<T>::postorder(Node<T>* start) {
	// left right root
	if (start != NULL) {
		postorder(start->left);
		postorder(start->right);
		cout << start->value << " " ;
	}
}

template<class T>
Node<T>* BST<T>::findparent(T val) {
	//assert(contains(val));
	Node<T>* parent;
	Node<T>* a ;
	parent = NULL;
	a = root;
	while (a!=NULL and a->value!=val) {
		parent = a;
		if (val < a->value) {
			// left  
			a = a->left;
		}
		else if (val > a->value ) {
			// right 
			a = a->right;
		}
	}
	return parent;
}

template<class T>
void BST<T>::remove(T val) {
	assert(contains(val));
	Node<T>* deleted_node = findnode(val);
	Node<T>* parent = findparent(val);
	// move leaf node has no childs
	if (deleted_node->left == NULL and deleted_node->right == NULL) {
		if (deleted_node == root) {
			root = NULL;
			delete deleted_node;
		}
		else {
			if (deleted_node == parent->right) {
				parent->right = NULL;
			}
			else {
				parent->left = NULL;
			}
			delete deleted_node; 
		}
	}
	// move node has one child
	else if (deleted_node->right != NULL and deleted_node->left == NULL) {
		if (deleted_node == root) {
			root = root->right;	
			delete deleted_node;
		}
		else {
			if (val < parent->value) {
				parent->left = deleted_node->right;
			}
			else if (val > parent->value) {
				parent->right = deleted_node->right;
			}
			delete deleted_node;
		}
	}
	else if (deleted_node->right == NULL and deleted_node->left != NULL) {
		if (root == deleted_node) {
			root = root->left;
			delete deleted_node;
		}
		else {
			if (val < parent->value) {
				parent->left = deleted_node->left;
			}
			else if (val>parent->value){
				parent->right = deleted_node->left;
			}
			delete deleted_node;
		}
	}
	// move node have 2 childs
	else if (deleted_node->right != NULL and deleted_node->left != NULL) {
		Node<T>* minNode = findMinNode(deleted_node->right);
		Node<T>* parentMinNode = findparent(minNode->value);
		deleted_node->value = minNode->value;

		if (parentMinNode == deleted_node) {
			parent->right = minNode->right; 
		}
		else {
			parentMinNode->left = minNode->right;
		}
		delete minNode;
	}
}

template<class T>
Node<T>* BST<T>::findMinNode(Node<T>* start) {
	Node<T>* minNode= start;
	while (true) {
		if (minNode->left == NULL) { return minNode; }
		minNode = minNode->left;
	}  
}

#pragma region competition

//=================================================================Competition==================================================================     

// find depth of most left and right leaf node
template<class T>
int BST<T>::findDepth_of_most_left_leaf(Node<T>* start) {
	int depth = 0;
	while (true) {
		if (start->left == NULL) { return depth; }
		depth++;
		start = start->left;
	}
}
template<class T>
int BST<T>::findDepth_of_most_right_leaf(Node<T>* start) {
	int depth = 0;
	while (true) {
		if (start->right== NULL) { return depth; }
		else {
			depth++;
			start = start->right;
		}
	}
}

// full 
template<class T>
bool BST<T>::fullBinaryTree(Node<T>*start) {
	// base case 
	if (start->left == NULL and start->right == NULL) {
		return true;
	}
	if (start->left == NULL or start->right == NULL) {
		return false;
	}
	// transition 
	return (fullBinaryTree(start->right) and fullBinaryTree(start->left));
}

// perfect
template<class T>		
bool BST<T>::isperfect(Node<T>* start, int d, int level) {
	// if tree is empty :)
	if (start == NULL) {
		return true;
	}
	if (start->left == NULL and start->right == NULL) {
		return (d == level);
	}
	if (start->left == NULL or start->right == NULL) {
		return false;
	}
	return(isperfect(start->left, d, level + 1) and isperfect(start->right, d, level + 1));
}
template<class T>
bool BST<T>::perfectBinaryTree(Node<T>* start) {
	int d = findDepth_of_most_left_leaf(root);
	return isperfect(root, d, 0);
}

// complete
template<class T>
bool BST<T>::completeBinaryTree(Node<T>* start ,int index ) {
	// base case :
	if (start == NULL) {
		return true;
	}
	if (index >= numodnodes) {
		return false;
	}
	// transition : 
	return (completeBinaryTree(start->left, (index * 2) + 1) and completeBinaryTree(start->right, (index * 2) + 2));
}

// balanced 
template<class T>
bool BST<T>::balancedBinaryTree(Node<T>* start ) {
	// base case : 
	if (start == NULL) {
		return true; 
	}
	int cntleft, cntright;
	cntleft = findDepth_of_most_left_leaf(start);
	cntright = findDepth_of_most_right_leaf(start);
	if (abs(cntleft - cntright) > 1) {
		return false;
	}
	// transition :
	return(balancedBinaryTree(start->left) and balancedBinaryTree(start->right) and abs(cntleft-cntright<=1));
}

// degenrate 
template<class T>
bool BST<T>::degenerate() {
	return !(rightbool and leftbool);
}

// display type of tree
template<class T>
void BST<T>:: displayTreeType() {
	cout << "Type(s) of tree : \n";
	if (fullBinaryTree(root)) {
		cout << "Full Binary search Tree \n"; 
	}
	if (perfectBinaryTree(root)) {
		cout << "Perfect Binary Search Tree \n";
	}
	if (completeBinaryTree(root,0)) {
		cout << "Complete Binary Search Tree\n"; 
	}
	if (balancedBinaryTree(root)) {
		cout << "Balanced Binary Search Tree\n";
	}
	if (degenerate()) {
		cout << "Degenerate Binary Search Tree\n";
	}
	cout << "\n";
}

#pragma endregion
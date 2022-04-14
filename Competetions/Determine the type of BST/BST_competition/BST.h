template<class T> 
class Node {
public:
	T value;
	Node<T>* left;
	Node<T>* right;
	Node();
	Node(T val);
};

template<class T> 
class BST{
	Node<T>* root;
	bool rightbool, leftbool;
	int numodnodes = 0;
public:
	BST();
	void traverse(int); 
	void inorder(Node<T>*);
	void preorder(Node<T>*);
	void postorder(Node<T>*);
	bool contains(T);
	Node<T>* findnode(T val);
	void insert(T); 
	// task competition
	bool fullBinaryTree(Node<T>*);
	bool perfectBinaryTree(Node<T>*);
	bool isperfect(Node<T>*, int, int);
	bool completeBinaryTree(Node<T>*,int);
	bool balancedBinaryTree(Node<T>*);
	bool degenerate();
	int findDepth_of_most_left_leaf(Node<T>*);
	int findDepth_of_most_right_leaf(Node<T>*);
	void displayTreeType();
	//end task
};


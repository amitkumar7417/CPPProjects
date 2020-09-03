#pragma once

#include "stdafx.h"
#include "StackImpl.h"
#include "QueueImpl.h"

template <typename  T>
class BinaryTreeNode {
public:
	BinaryTreeNode(T val) :data(val), left(nullptr), right(nullptr) {

	}
	int data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
};

template <typename T>
class BinaryTree {
private:
	BinaryTreeNode<T> * root;
public:
	BinaryTree();
	BinaryTree(const vector<T> &v);
	~BinaryTree();
	void insertToBST(T val);
	void preOrder(BinaryTreeNode<T> *root);
	void postOrder(BinaryTreeNode<T> *root);
	void inOrder(BinaryTreeNode<T> *root);
	void levelOrderTraversal(BinaryTreeNode<T> *root);
	//void deleteNode(T val);
	void TreeSize(BinaryTreeNode<T> *root, int &n);
	BinaryTreeNode<T> *getRoot() {
		return root;
	}

	void setRoot(BinaryTreeNode<T>* rootNode) {
		root = rootNode;
	}
	void MaxElement(BinaryTreeNode<T> *root, int &n);
	bool searchElement(BinaryTreeNode<T> *root, int n);
	void reverseLevelOrderTraversal(BinaryTreeNode<T> *root);
	void DeleteBinaryTree(BinaryTreeNode<T> *root);
	int findHeightWithoutRecursion(BinaryTreeNode<T> *root);
	BinaryTreeNode<T> * FindDeepestNode(BinaryTreeNode<T> *root);
	bool DeleteNodeInBinaryTree(T data);
	void FindParentNode(BinaryTreeNode<T> *root,BinaryTreeNode<T> *childNode, BinaryTreeNode<T>* &parentNode, int &whichChild,bool &found);
	void FindAllLeafNodes(BinaryTreeNode<T> *root, vector<T> &leafNodes);
	void FindAllFullNodes(BinaryTreeNode<T> *root, vector<T> &fullNodes);
	void FindAllLeafNodesUsingRecursion(BinaryTreeNode<T> *root, vector<T> &leafNodes);
	void AreStructurallySame(BinaryTreeNode<T>* r1, BinaryTreeNode<T>* r2, bool &isSame);
	void FindSumOfAllElementInTreeUsingRecursion(BinaryTreeNode<T>* root, int &sum);
	void FindSumOfAllElementInTreeWithoutRecursion(BinaryTreeNode<T>* root, int &sum);
	void PrintPathToLeafNodes(BinaryTreeNode<T> *root, vector<T> nodesToLeaf);
	void FindPathWithAGivenSum(BinaryTreeNode<T> *root, int sum, vector<T> path, pair<bool, vector<T>>& output);
	void CreateMirrorTree(BinaryTreeNode<T> *root, int pos, BinaryTree<T>& mirrorTree,BinaryTreeNode<T> * mirrorRoot);
	BinaryTreeNode<T> * ConvertToMirrorTree(BinaryTreeNode<T> *root);
	bool CheckIfMirrorTree(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2);
	bool FindLCA(BinaryTreeNode<T> *root, T node1, T node2, T& lca);
	void FindPathFromRootToNode(BinaryTreeNode<T> *root, T node, vector<BinaryTreeNode<T> *> path, vector<BinaryTreeNode<T> *>&output);
	void VerticalSum(BinaryTreeNode<T> *root, int column, unordered_map<int, int>& output);
	void ZigZagTraversal(BinaryTreeNode<T> *root);
};

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {

}

template <typename T>
BinaryTree<T>::BinaryTree(const vector<T> &v) {
	//Creates a binary tree using the contents of the passed in vector
	for (const auto& p : v) {
		insertToBST(p);
	}
}
template <typename T>
BinaryTree<T>::~BinaryTree() {

}

template <typename T>
void BinaryTree<T>::insertToBST(T val) {
	BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(val);
	if (root == nullptr) {
		root = newNode;
		return;
	}
	//Find a position to insert into the binary tree
	BinaryTreeNode<T> *tmp = root;
	BinaryTreeNode<T> *parentNode = nullptr;
	while (tmp != nullptr) {
		parentNode = tmp;
		if (val < tmp->data) {
			tmp = tmp->left;
			if (tmp == nullptr) {
				parentNode->left = newNode;
			}
		}
		else {
			tmp = tmp->right;
			if (tmp == nullptr) {
				parentNode->right = newNode;
			}
		}
	}
}

template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return;

	cout << root->data << '\t';
	preOrder(root->left);
	preOrder(root->right);


}

template <typename T>
void BinaryTree<T> ::inOrder(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return;

	inOrder(root->left);
	cout << root->data << '\t';
	inOrder(root->right);
}

template <typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << '\t';
}

template<typename T>
void BinaryTree<T>::levelOrderTraversal(BinaryTreeNode<T> *root) {
	BinaryTreeNode<T> *tmp = root;
	Queue<BinaryTreeNode<T> *> *s = Queue<BinaryTreeNode<T> *>::CreateQueue();
	s->add(root);
	if (tmp != nullptr) {
		while (!s->isEmpty()) {
			BinaryTreeNode<T>* val = s->front();
			cout << val->data << '\t';
			if(val->left != nullptr)
				s->add(val->left);
			if(val->right != nullptr)
				s->add(val->right);
		}
	}
	s->DeleteQueue();

}

template <typename T>
void BinaryTree<T>::TreeSize(BinaryTreeNode<T> *root, int &n) {
	if (root == nullptr)
		return;

	TreeSize(root->left,n);
	++n;
	TreeSize(root->right,n);
}

template <typename T>
void BinaryTree<T>::MaxElement(BinaryTreeNode<T> *root, int &n) {
	if (root == nullptr)
		return;

	MaxElement(root->left, n);
	if (root->data > n)
		n = root->data;
	MaxElement(root->right, n);
}

template <typename T>
bool BinaryTree<T>::searchElement(BinaryTreeNode<T> *root, int n) {
	if (root == nullptr)
		return false;

	if (n == root->data)
		return true;
	//Find in left subtree
	bool isPresent = searchElement(root->left, n);
	if (isPresent)
		return true;
	else {
		//Find in right subtree
		bool isPresent = searchElement(root->right, n);
		if (isPresent)
			return true;
	}
	return false;
}

template <typename T>
void BinaryTree<T>::reverseLevelOrderTraversal(BinaryTreeNode<T> *root) {
	Queue<BinaryTreeNode<T> *> *queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	queue->add(root);
	Stack<BinaryTreeNode<T> *> *stack = Stack<BinaryTreeNode<T> *>::CreateStack();
	while (!queue->isEmpty()) {
		BinaryTreeNode<T> *frontNode = queue->front();
		if (frontNode->right != nullptr) {
			queue->add(frontNode->right);
		}
		if (frontNode->left != nullptr) {
			queue->add(frontNode->left);
		}
		stack->push(frontNode);
	}
	queue->DeleteQueue();
	while (!stack->isEmpty()) {
		cout << stack->pop()->data << '\t';
	}
	cout << endl;
	stack->DeleteStack();
}


//Before deleting the parent node we should delete its children node first.
//We can use the post order traversal as it does the work without storing anything.
//We can also use the reverse order traversal to delete the binary tree.
template<typename T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return;

	DeleteBinaryTree(root->right);
	DeleteBinaryTree(root->left);
	delete(root);
}

template <typename T>
int BinaryTree<T>::findHeightWithoutRecursion(BinaryTreeNode<T> *root) {
	//Using level order traversal we could find the height of the binary tree.
	//The total number of levels in a binary tree is equal to the height of the binary tree.
	if (root == nullptr)
		return 0;

	int height = 0;
	Queue<BinaryTreeNode<T> *> * queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	queue->add((BinaryTreeNode<T> *)nullptr);
	while(1) {
		root = queue->front();
		if (root == nullptr) {
			++height;
			BinaryTreeNode<T> *nextNode = queue->peek();
			if (nextNode == nullptr)
				break;
			else
				queue->add((BinaryTreeNode<T> *)nullptr);
		}
		else {
			if (root->left != nullptr)
				queue->add(root->left);

			if (root->right != nullptr)
				queue->add(root->right);
		}
	}
	return height;
}

template<typename T>
BinaryTreeNode<T> * BinaryTree<T>::FindDeepestNode(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return nullptr;
	//Deepest node is the last node in the level order traversal
	Queue<BinaryTreeNode<T> *> *queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	BinaryTreeNode<T> *tmp = nullptr;
	while (!queue->isEmpty()) {
		root = queue->front();
		tmp = root;
		if (root->left != nullptr)
			queue->add(root->left);
		if (root->right != nullptr)
			queue->add(root->right);
	}
	return tmp;
}

template<typename T>
bool BinaryTree<T>::DeleteNodeInBinaryTree(T data) {
	//Algotithm in this function can be used only with binary tree which are not BST tree.
	//BST tree maintains an order of the nodes so following algorithm cannot be used.
	BinaryTreeNode<T> * root = getRoot();
	//Find the node address of the node which has data in it.
	if (root == nullptr) {
		cout << "Empty binary tree" << endl;
		return false;
	}
	
	//Do level order traversal and find the node to be deleted
	BinaryTreeNode<T> *nodeToBeDeleted = nullptr, *deepestNode = nullptr;
	Queue<BinaryTreeNode<T> *> queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	while (!queue->isEmpty()) {
		root = queue->front();
		deepestNode = root;
		if (root->data == data) {
			nodeToBeDeleted = root;
		}
		if (root->left != nullptr) {
			queue->add(root->left);
		}
		if (root->right != nullptr) {
			queue->add(root->right);
		}
	}

	if (nodeToBeDeleted == nullptr) {
		cout << "Node to be deleted could not be found" << endl;
		return false;
	}

	//Find the deepestNode's parent and whether deepestNode is left(-1) or right child(+1)
	int whichChild = 0;
	BinaryTreeNode<T> * parentNode = nullptr;
	bool found = false;
	FindParentNode(getRoot(),deepestNode, parentNode, whichChild,found);
	if (whichChild == -1) {
		parentNode->left = nullptr;
	}
	else {
		parentNode->right = nullptr;
	}

	nodeToBeDeleted->data = deepestNode->data;
	delete deepestNode;
	return true;

}

template<typename T>
void BinaryTree<T>::FindParentNode(BinaryTreeNode<T> *root,BinaryTreeNode<T> *childNode, BinaryTreeNode<T>* &parentNode, int &whichChild,bool &found) {
	//Do pre-order traversal
	if (root == nullptr)
		return;

	//Process node
	if (root->left == childNode) {
		parentNode = root;
		whichChild = -1;
		found = true;
	}
	else if (root->right == childNode) {
		parentNode = root;
		whichChild = 1;
		found = true;
	}

	//Traverse left tree
	if(!found)
		FindParentNode(root->left,childNode,parentNode,whichChild,found);
	//Traverese right tree
	if(!found)
		FindParentNode(root->right,childNode,parentNode,whichChild,found);
}

template <typename T>
void BinaryTree<T>::FindAllLeafNodes(BinaryTreeNode<T> *root, vector<T> &leafNodes) {
	if (root == nullptr)
		return;
	
	Queue<BinaryTreeNode<T> *> *queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	while (!queue->isEmpty()) {
		root = queue->front();
		if (root->left == nullptr && root->right == nullptr)
			leafNodes.push_back(root->data);

		if (root->left != nullptr)
			queue->add(root->left);

		if (root->right != nullptr)
			queue->add(root->right);
	}
}

template <typename T>
void BinaryTree<T>::FindAllFullNodes(BinaryTreeNode<T> *root, vector<T> &fullNodes) {
	if (root == nullptr)
		return;

	Queue<BinaryTreeNode<T> *> *queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	while (!queue->isEmpty()) {
		root = queue->front();
		if (root->left != nullptr && root->right != nullptr)
			fullNodes.push_back(root->data);

		if (root->left != nullptr)
			queue->add(root->left);

		if (root->right != nullptr)
			queue->add(root->right);
	}
}

template<typename T>
void BinaryTree<T>::FindAllLeafNodesUsingRecursion(BinaryTreeNode<T> *root, vector<T> &leafNodes) {
	//Do preorder traversal
	if (root == nullptr)
		return;

	if (root->left == nullptr && root->right == nullptr)
		leafNodes.push_back(root->data);

	FindAllLeafNodesUsingRecursion(root->left, leafNodes);
	FindAllLeafNodesUsingRecursion(root->right, leafNodes);

}

template<typename T>
void BinaryTree<T>::AreStructurallySame(BinaryTreeNode<T>* r1, BinaryTreeNode<T>* r2,bool &isSame) {
	if (r1 == nullptr && r2 == nullptr) {
		isSame = true;
		return;
	}
	
	if (r1 && !r2 || !r1&&r2) {
		isSame = false;
		return;
	}

	//Do pre-order traversal
	if (r1->data != r2->data)
		isSame = false;

	if (isSame) {
		AreStructurallySame(r1->left, r2->left,isSame);
	}
	if (isSame) {
		AreStructurallySame(r1->right, r2->right,isSame);
	}

}

template<typename T>
void BinaryTree<T>::FindSumOfAllElementInTreeUsingRecursion(BinaryTreeNode<T>* root, int &sum) {
	if (root == nullptr) {
		sum = sum + 0;
		return;
	}

	//Do preorder traversal
	sum = sum + root->data;
	FindSumOfAllElementInTreeUsingRecursion(root->left, sum);
	FindSumOfAllElementInTreeUsingRecursion(root->right,sum);
}

template<typename T>
void BinaryTree<T>::FindSumOfAllElementInTreeWithoutRecursion(BinaryTreeNode<T>* root, int &sum) {
	if (root == nullptr)
		return;

	Queue<BinaryTreeNode<T> *> *queue = Queue<BinaryTreeNode<T> *>::CreateQueue();
	queue->add(root);
	while (!queue->isEmpty()) {
		root = queue->front();
		sum = sum + root->data;
		if (root->left != nullptr)
			queue->add(root->left);
		if (root->right != nullptr)
			queue->add(root->right);
	}
}

template<typename T>
void BinaryTree<T>::PrintPathToLeafNodes(BinaryTreeNode<T> *root, vector<T> nodesToLeaf) {
	if (root == nullptr)
		return;

	nodesToLeaf.push_back(root->data);
	
	if (root->left == nullptr && root->right == nullptr) {
		for (const auto &v : nodesToLeaf)
			cout << v << '\t';

		cout << endl;
	}
	else {
		PrintPathToLeafNodes(root->left, nodesToLeaf);
		PrintPathToLeafNodes(root->right, nodesToLeaf);
	}
}

template<typename T>
void BinaryTree<T>::FindPathWithAGivenSum(BinaryTreeNode<T> *root, int sum, vector<T> path, pair<bool,vector<T>>& output) {
	if (root == nullptr)
		return;

	path.push_back(root->data);
	int remainingSum = sum - root->data;
	if (remainingSum == 0) {
		output.first = true;
		output.second = vector<T>(path.begin(), path.end());
		return;
	}

	if (root->left && !output.first) {
		FindPathWithAGivenSum(root->left,remainingSum,path,output);
	}
	if (root->right && !output.first) {
		FindPathWithAGivenSum(root->right, remainingSum,path,output);
	}

}

template<typename T>
void BinaryTree<T>::CreateMirrorTree(BinaryTreeNode<T> *root,int pos,BinaryTree<T>& mirrorTree,BinaryTreeNode<T> * mirrorRoot) {
	//Creates a new mirror tree from input tree 
	if (root == nullptr)
		return ;
	
	T data = root->data;
	BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
	
	if (pos == 0) {
		//Create root node for mirror tree.
		mirrorTree.root = newNode;
		mirrorRoot = newNode;
	}
	//PreOrder Traversal: As we have to always create parent node first then its child nodes
	else if (pos == -1) {
		//Node should go to the right subtree in mirror tree
		mirrorRoot->right = newNode;
	}
	else if (pos == 1) {
		//Node should go to the left subtree in mirror tree
		mirrorRoot->left = newNode;

	}
	mirrorRoot = newNode;
	if (root->left)
		CreateMirrorTree(root->left,-1, mirrorTree, mirrorRoot);
	if (root->right)
		CreateMirrorTree(root->right, 1, mirrorTree,mirrorRoot);
}

template<typename T>
BinaryTreeNode<T> * BinaryTree<T>::ConvertToMirrorTree(BinaryTreeNode<T> *root) {
	BinaryTreeNode<T> *tmp;
	if (root) {
		//This has to be post order traversal because the left and right child nodes needs to be processed before its parent node.
		ConvertToMirrorTree(root->left);
		ConvertToMirrorTree(root->right);
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}

	return root;

}

template<typename T>
bool BinaryTree<T>::CheckIfMirrorTree(BinaryTreeNode<T>* root1,BinaryTreeNode<T>* root2) {
	if (!root1 && !root2)
		return true;

	if ((root1 && !root2) || (!root1&&root2))
		return false;

	if (root1->data != root2->data)
		return false;

	bool status = CheckIfMirrorTree(root1->left, root2->right);
	if (status)
	status = CheckIfMirrorTree(root1->right,root2->left);
	
	return status;
}

template<typename T>
bool BinaryTree<T>::FindLCA(BinaryTreeNode<T> *root, T node1, T node2, T& lca) {
	//Do pre order traversal to find path to node1 and node2;
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return false;
	}

	vector<BinaryTreeNode<T> *> path1, path2;
	vector<BinaryTreeNode<T> *> tmppath;
	FindPathFromRootToNode(root, node1,tmppath, path1);
	if (path1.size() == 0) {
		cout << "Path to " << node1 << " couldn't be found" << endl;
		return false;
	}
	tmppath.clear();
	FindPathFromRootToNode(root, node2,tmppath, path2);
	if (path2.size() == 0) {
		cout << "Path to " << node2 << " couldn't be found" << endl;
		return false;
	}	

	auto iter1 = path1.begin();
	auto iter2 = path2.begin();
	for (; iter1 != path1.end(), iter2 != path2.end(); ++iter1, ++iter2) {
		if ((*iter1)->data == (*iter2)->data) {
			lca = (*iter1)->data;
		}
		else {
			break;
		}
	}
	return true;
}

template<typename T>
void BinaryTree<T>::FindPathFromRootToNode(BinaryTreeNode<T> *root, T node, vector<BinaryTreeNode<T> *> path, vector<BinaryTreeNode<T> *>&output) {
	if (root == nullptr)
		return;

	path.push_back(root);
	if (root->data == node) {
		//Fill the path with the vector
		output = vector<BinaryTreeNode<T> *>(path.begin(),path.end());
		return;
	}
	else {
		FindPathFromRootToNode(root->left, node, path, output);
		FindPathFromRootToNode(root->right, node, path, output);
	}
}

template<typename T>
void BinaryTree<T>::VerticalSum(BinaryTreeNode<T> *root, int column, unordered_map<int, int>& output) {
	if (root == nullptr)
		return;
	//Do inorder traversal
	VerticalSum(root->left, column - 1, output);
	output[column] = output[column] + root->data;
	VerticalSum(root->right, column + 1, output);
}

template<typename T>
void BinaryTree<T>::ZigZagTraversal(BinaryTreeNode<T> *root) {
	if (root == nullptr)
		return;

	int leftToRight = 1;
	Stack<BinaryTreeNode<T> *> *currLevel = Stack<BinaryTreeNode<T> *>::CreateStack();
	Stack<BinaryTreeNode<T> *> *nxtLevel = Stack<BinaryTreeNode<T> *>::CreateStack();
	currLevel->push(root);

	while (!currLevel->isEmpty()) {
		root = currLevel->pop();
		cout << root->data << '\t';
		if (leftToRight) {
			if(root->left)
				nxtLevel->push(root->left);
			if(root->right)
				nxtLevel->push(root->right);
		}
		else {
			if (root->right)
				nxtLevel->push(root->right);
			if (root->left)
				nxtLevel->push(root->left);
		}

		if (currLevel->isEmpty()) {
			cout << endl;
			leftToRight = 1 - leftToRight;
			//Swap the stack
			Stack<BinaryTreeNode<T> *> *tmp = currLevel;
			currLevel = nxtLevel;
			nxtLevel = tmp;
		}
	}

	currLevel->DeleteStack();
	nxtLevel->DeleteStack();
}
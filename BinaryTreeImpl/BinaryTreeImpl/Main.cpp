#include "stdafx.h"
#include <vector>
#include "BinaryTreeImpl.h"
int main()
{
	vector<int> v = { 10,6,12,4,8,16,3,5,14,18 };
	BinaryTree<int> bt(v);

	cout << "Inorder Traversal" << endl;
	bt.inOrder(bt.getRoot());
	cout << endl;

	cout << "PreOrder Traversal" << endl;
	bt.preOrder(bt.getRoot());
	cout << endl;

	cout << "PostOrder Traversal" << endl;
	bt.postOrder(bt.getRoot());
	cout << endl;

	cout << "Level Order Traversal" << endl;
	bt.levelOrderTraversal(bt.getRoot());
	cout << endl;

	cout << "Reverse Level Order Traversal" << endl;
	bt.reverseLevelOrderTraversal(bt.getRoot());

	int n = 0;
	bt.TreeSize(bt.getRoot(), n);
	cout << "Size of tree :" << n << endl;

	int maxElement = INT_MIN;
	bt.MaxElement(bt.getRoot(),maxElement);
	cout << "Max element in tree :" << maxElement << endl;

	int searchElement = 3; //75
	bool isPresent = bt.searchElement(bt.getRoot(),searchElement);
	cout << "Is element present in tree :" << isPresent << endl;

	cout << "Deleting a binary tree" << endl;
	bt.DeleteBinaryTree(bt.getRoot());
	int sizeOfDeletedTree = 0;
	cout << "Size of binary tree after deleting the tree : " << sizeOfDeletedTree << endl;
    
	//Constructing binary tree again.
	BinaryTree<int> bt2(v);
	bt = bt2;
	//Find the height of the binary tree.

	cout << "Inorder Traversal" << endl;
	bt.inOrder(bt.getRoot());
	cout << endl;

	cout << "Calculating height of binary tree" << endl;
	int height = bt.findHeightWithoutRecursion(bt.getRoot());
	cout << "Height of binary tree : " << height <<endl;

	BinaryTreeNode<int> *deepestNode = bt.FindDeepestNode(bt.getRoot());
	if (deepestNode != nullptr) {
		cout << "Deepest Node in the binary tree : " << deepestNode->data << endl;
	}

	//Find parent node
	BinaryTreeNode<int>* parentNode = nullptr;
	int whichChild = 0;
	bool found = false;
	bt.FindParentNode(bt.getRoot(), deepestNode,parentNode, whichChild, found);
	if (found)
		cout << "Parent Node for the deepest node is : " << parentNode->data << endl;
	else
		cout << "Parent Node for the deepest node couldn't be found" << endl;

	cout << "Print all the leaf nodes" << endl;
	vector<int> leafNodes;
	bt.FindAllLeafNodes(bt.getRoot(),leafNodes);
	for (const auto& node : leafNodes)
		cout << node << '\t';
	cout << endl;
	cout << "Print all the full nodes" << endl;
	vector<int> fullNodes;
	bt.FindAllFullNodes(bt.getRoot(),fullNodes);
	for (const auto& node : fullNodes)
		cout << node << '\t';
	cout << endl;

	//Check if two trees are structurally same
	vector<int> v2 = { 10,6,12,4,8,16,3,5,14,18 };
	BinaryTree<int> bt3(v2);
	bool areSame = true;
	bt.AreStructurallySame(bt.getRoot(), bt3.getRoot(), areSame);
	cout << "Are same : " << areSame  << endl;

	vector<int> v3 = { 10, 6, 12, 4, 8, 16, 3, 5,14,18,19,20 };
	BinaryTree<int> bt4(v3);
	areSame = true;
	bt.AreStructurallySame(bt.getRoot(), bt4.getRoot(), areSame);
	cout << "Are same : " << areSame << endl;
	
	//Find sum of all elements in a binary tree
	int sum = 0;
	bt.FindSumOfAllElementInTreeUsingRecursion(bt.getRoot(),sum);
	cout << "Sum of all elements in a binary tree using recursion : " << sum << endl;

	sum = 0;
	bt.FindSumOfAllElementInTreeWithoutRecursion(bt.getRoot(), sum);
	cout << "Sum of all elements in a binary tree without using recursion : " << sum << endl;
	
	
	cout << "Print path to leaf nodes" << endl;
	vector<int> nodesToLeaf;
	bt.PrintPathToLeafNodes(bt.getRoot(), nodesToLeaf);
	
	cout << "Find path with a given sum" << endl;
	
	int pathSum1 = 24;
	
	vector<int> path;
	pair<bool, vector<int>> output1;
	bt.FindPathWithAGivenSum(bt.getRoot(), pathSum1,path, output1);
	cout << "Is path found with sum " << pathSum1 << " found  : " << output1.first << endl;
	if(output1.first){
		cout << "Printing path..." << endl;
		for (const auto& v : output1.second)
			cout << v << '\t';
		cout << endl;
	}
	int pathSum2 = 102;
	pair<bool, vector<int>> output2;
	path = {};
	bt.FindPathWithAGivenSum(bt.getRoot(), pathSum2, path, output2);
	cout << "Is path found with sum " << pathSum2 << " found  : " << output2.first << endl;
	if (output2.first) {
		cout << "Printing path..." << endl;
		for (const auto& v : output2.second)
			cout << v << '\t';
		cout << endl;
	}

	//Create mirror tree
	BinaryTree<int> mirrorTree;
	bt.CreateMirrorTree(bt.getRoot(),0, mirrorTree ,mirrorTree.getRoot());
	cout << "Printing inorder traversal for mirror tree" << endl;
	mirrorTree.inOrder(mirrorTree.getRoot());
	cout << endl;

	//Check if mirror tree
	cout << "Are they mirror : " << bt.CheckIfMirrorTree(bt.getRoot(), mirrorTree.getRoot()) << endl;
	cout << "Are they mirror : " << bt.CheckIfMirrorTree(bt.getRoot(), bt.getRoot()) << endl;

	//Covert to mirror tree
	bt.setRoot(bt.ConvertToMirrorTree(bt.getRoot()));
	cout << "Printing inorder traversal for self converted mirror tree" << endl;
	bt.inOrder(bt.getRoot());
	cout << endl;
	
	//Find least common ancestor
	int lca;
	if (bt.FindLCA(bt.getRoot(), 4, 8, lca)) {
		cout << "LCA of 4 and 8 is " << lca << endl;
	}
	lca = -1;
	if (bt.FindLCA(bt.getRoot(), 3, 18, lca)) {
		cout << "LCA of 4 and 8 is " << lca << endl;
	}

	cout << "Print vertical sum" << endl;
	std::unordered_map<int, int> output;
	bt.VerticalSum(bt.getRoot(), 0, output);
	for (auto iter = output.begin(); iter != output.end(); iter++) {
		cout << "[" << iter->first << "]" << "=" << iter->second << endl;
	}

	cout << "Print ZigZag traversal of the tree" << endl;
	bt.ZigZagTraversal(bt.getRoot());


	return 0;
}

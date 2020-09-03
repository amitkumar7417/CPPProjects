#pragma once

//Forward Declaration
class BinaryHeap;

class BinaryHeapImpl {

public:
	BinaryHeapImpl(){

	}

	~BinaryHeapImpl() {

	}

	int deleteMaxElement(BinaryHeap *root);
	int insertElement(BinaryHeap *root, int val);
	void percolateDown(BinaryHeap * root, int index);
	void resizeHeap(BinaryHeap * &root);
	void buildHeap(BinaryHeap *root, const std::vector<int> &A);
	int getParent(BinaryHeap * root, int index);
	int getLeftChild(BinaryHeap * root, int index);
	int getRightChild(BinaryHeap * root, int index);
	int getMaxElement(BinaryHeap *root);
	void deleteHeap(BinaryHeap* root);
	void printHeap(BinaryHeap* root);
	void heapSort(vector<int>& A);
};
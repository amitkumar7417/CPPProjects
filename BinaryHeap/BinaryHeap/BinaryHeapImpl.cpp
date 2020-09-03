#include "stdafx.h"
#include "BinaryHeapImpl.h"
#include "BinaryHeap.h"
int BinaryHeapImpl::getParent(BinaryHeap * root, int childIndex) {

	if (childIndex <= 0 || childIndex >= root->size)
		return -1;

	return (childIndex - 1) / 2;

}

int BinaryHeapImpl::getLeftChild(BinaryHeap * root, int parentIndex) {
	int left = (2 * parentIndex) + 1;
	if (left >= root->size)
		return -1;

	return left;


}
int BinaryHeapImpl::getRightChild(BinaryHeap * root, int parentIndex) {
	int right = (2 * parentIndex) + 2;
	if (right >= root->size)
		return -1;

	return right;

}

int BinaryHeapImpl::getMaxElement(BinaryHeap *root) {
	if (root->size == 0)
		return -1;

	return root->arr[0];
}

int BinaryHeapImpl::deleteMaxElement(BinaryHeap *root) {
	//To delete an element from heap, we just need to delete the element from the root. This is the only operation 
	//supported by standard heap.

	if (root->size == 0)
		return -1;

	int deletedElement = root->arr[0];
	//Copy the last element in heap to the root of the heap.
	root->arr[0] = root->arr[root->size - 1];
	//Reduce the size by 1
	root->size = root->size - 1;
	//Heapify the heap again 
	percolateDown(root, 0);
	return deletedElement;
}

int BinaryHeapImpl::insertElement(BinaryHeap *root, int val) {

	//Check if the current size of the heap is equal to its capacity.
	//If yes then resize the heap
	if (root->size == root->capacity) {
		resizeHeap(root);
	}


	//Insert the element to the end of the heap.
	root->arr[root->size] = val;
	root->size = root->size + 1;
	//Heapify the heap from bottom to top
	int index = (root->size) - 1;
	int parent_ind = getParent(root, index);
	while (parent_ind != -1 && root->arr[parent_ind] < val) {
		root->arr[index] = root->arr[parent_ind];
		root->arr[parent_ind] = val;
		index = parent_ind;
		parent_ind = getParent(root, index);
	}

	return index;
}

void BinaryHeapImpl::resizeHeap(BinaryHeap * &root) {
	int *oldArray = root->arr;
	int old_size = root->size;
	root->arr = new int[root->capacity * 2];
	for (int i = 0; i < old_size; i++) {
		root->arr[i] = oldArray[i];
	}
	root->size = old_size;
	root->capacity = root->capacity * 2;
	delete[] oldArray;

}

void BinaryHeapImpl::percolateDown(BinaryHeap * root, int index) {
	if (root->size == 0)
		return;


	int l = getLeftChild(root, index);
	int r = getRightChild(root, index);
	if (l == -1 && r == -1)
		return;
	int max_ind = index;
	if (l != -1 && root->arr[index] < root->arr[l])
		max_ind = getLeftChild(root, index);

	if (r != -1 && root->arr[max_ind] < root->arr[r])
		max_ind = getRightChild(root, index);

	if (max_ind != index) {
		//Swap;
		int temp = root->arr[max_ind];
		root->arr[max_ind] = root->arr[index];
		root->arr[index] = temp;
	}
	else
		return;
	percolateDown(root, max_ind);
}

void BinaryHeapImpl::buildHeap(BinaryHeap *root, const std::vector<int> &A) {
	if (root == nullptr)
		return;

	int n = (int)A.size();
	while (root->capacity < n) {
		resizeHeap(root);
	}

	for (int i = 0; i < n; i++) {
		root->arr[i] = A[i];
	}
	root->size = n;
	//Find last non leaf node
	int lastNonLeafNode_Ind = getParent(root, n - 1/*last index*/);
	for (int i = lastNonLeafNode_Ind; i >= 0; i--) {
		percolateDown(root, i);
	}


}

void BinaryHeapImpl::deleteHeap(BinaryHeap* root) {
	if (root == nullptr)
		return;
	delete[] root->arr;
	delete root;
	root = nullptr;
}

void BinaryHeapImpl::printHeap(BinaryHeap* root) {
	for (int i = 0; i < root->size; i++)
		cout << root->arr[i] << '\t';
	cout << endl;
}

void BinaryHeapImpl::heapSort(vector<int>& A) {
	int n = (int)A.size();
	BinaryHeap tmpHeap(n, HEAP_TYPE::MAX_HEAP);
	tmpHeap.create(A);
	int count = tmpHeap.count();
	for (int i = count - 1; i >= 0; i--) {
		int temp = tmpHeap.getData(0);
		tmpHeap.setData(0,tmpHeap.getData(tmpHeap.count() - 1));
		tmpHeap.setData(tmpHeap.count() - 1, temp);
		tmpHeap.setSize(tmpHeap.count()-1);
		percolateDown(&tmpHeap, 0);
	}

	tmpHeap.setSize(count);
	for (int i = 0; i < count; i++)
		A[i] = tmpHeap.getData(i);

	//deleteHeap(h);
}
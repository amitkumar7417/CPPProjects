#pragma once
#include "stdafx.h"
#include "BinaryHeapImpl.h"

enum class HEAP_TYPE {
	MAX_HEAP = 1,
	MIN_HEAP = 0
};

class BinaryHeap {
private:
	BinaryHeapImpl * impl;
	BinaryHeap *root;
public:
	BinaryHeap(int _capacity, HEAP_TYPE _type) : capacity(_capacity), type(_type), size(0)
	{
		arr = new int[capacity];
		impl = new BinaryHeapImpl;
	}
	~BinaryHeap() {

	}
	int *arr;
	int capacity;
	int size;
	HEAP_TYPE type;  //0 = MinHeap, 1 = MaxHeap;
	inline BinaryHeapImpl * getImpl() {
		return impl;
	}

	inline void setImpl(BinaryHeapImpl *_impl) {
		impl = _impl;
	}

	void create(const vector<int> &num) {
		impl->buildHeap(this, num);
	}

	inline int count() {
		return size;
	}

	inline void print() {
		impl->printHeap(this);
	}

	inline int insert(int val) {
		return impl->insertElement(this, val);
	}

	inline int deleteMax() {
		return impl->deleteMaxElement(this);
	}

	inline void sort(vector<int> &num) {
		impl->heapSort(num);

	}

	int getData(int index) {
		int data = -1;
		if(index < size)
			data = arr[index];
		return data;
	}

	void setData(int index, int val) {
		if(index < size)
			arr[index] = val;
	}

	inline void setSize(int count) {
		size = count;
	}
};




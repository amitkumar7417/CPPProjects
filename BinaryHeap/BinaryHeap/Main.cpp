#include "stdafx.h"
#include "BinaryHeap.h"

int main()
{
	BinaryHeap *heap = new BinaryHeap(10, HEAP_TYPE::MAX_HEAP);
	//BinaryHeap *root = heapImpl.getRoot();
	vector<int> A = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	//Build Heap
	heap->create(A);
	int heap_size = heap->count();
	cout << "Size after building = " << heap_size << endl;

	cout << "Printing the heap after building" << endl;
	heap->print();
	cout << endl;
	//Inserting an element
	int insert_index = heap->insert(19);
	heap_size = heap->count();
	cout << "Element = " << heap->getData(insert_index) << " inserted at index " << insert_index << endl;
	cout << "Size of heap after insertion = " << heap_size << endl;
	cout << "Printing the heap after inserting 19" << endl;
	heap->print();
	cout << endl;
	//Delete Max Element
	int deletedElement = heap->deleteMax();
	heap_size = heap->count();
	cout << "Deleted Element = " << deletedElement << " Size after deletion = " << heap_size << endl;
	cout << "Printing the heap after deleting max element" << endl;
	heap->print();
	cout << endl;
	
	//Heap Sort
	vector<int> num = { 6,5,3,1,8,7,2,4 };
	heap->sort(num);
	cout << "After sorting:" << endl;
	for (auto v : num)
		cout << v << '\t';
	cout << endl;

}


#pragma once

#include "stdafx.h"
#include <list>
#include <unordered_map>
#include "LinkedList.h"



class LRUImpl {
	int size;
	int count;
	unordered_map<int, LinkedListNode *> uMap; //Need hashtable for O(1) search complexity;
	LinkedList *list;
public:
	LRUImpl(int _size): size(_size),count(0) {
		list = new LinkedList();
	}
	int get(int key);
	void put(int key, int val);
	void cacheDisplay();
};
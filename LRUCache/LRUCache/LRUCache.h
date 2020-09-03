#pragma once

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Node {
	int key, value;
public:
	Node(int _key, int _val) :key(_key), value(_val) {

	}
	~Node() {

	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}

	void setValue(int val) {
		value = val;
	}

};

class LRUCache {
	list<Node *> cacheList;
	unordered_map<int, list<Node *>::iterator> uMap;
	int cacheSize;
public:
	LRUCache(int _size) :cacheSize(_size) {

	}
	~LRUCache() {

	}

	int get(int key);
	int accessCache(int key);
	int updateCache(int key, int value);
	void displayCache();
};


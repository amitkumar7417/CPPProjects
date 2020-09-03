#pragma once

class LinkedListNode {
public:
	LinkedListNode(pair<int,int> val) : data(val),prev(nullptr),next(nullptr) {

	}
	~LinkedListNode() {

	}
	pair<int,int> data;
	LinkedListNode* prev;
	LinkedListNode* next;
};

class LinkedList {
	LinkedListNode *head;
	LinkedListNode *tail;
public:
	LinkedList() :head(nullptr), tail(nullptr) {

	}
	~LinkedList() {

	}
	LinkedListNode* insertAtFront(pair<int,int> val);
	pair<int, int>  deleteTailNode();
	pair<int,int> getNode(LinkedListNode* address);
	void update(int key, int val);
	void display();
};

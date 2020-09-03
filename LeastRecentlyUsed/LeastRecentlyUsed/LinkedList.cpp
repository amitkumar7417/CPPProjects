#include "stdafx.h"
#include "LinkedList.h"

LinkedListNode* LinkedList::insertAtFront(pair<int,int> val) {
	LinkedListNode *newNode = new LinkedListNode(val);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return head;
	}
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return newNode;
}

pair<int,int> LinkedList::deleteTailNode() {
	if (tail == nullptr)
		return make_pair(-1,-1);

	LinkedListNode *prevNode = tail->prev;
	pair<int, int> kvp = tail->data;
	delete tail;
	prevNode->next = nullptr;
	tail = prevNode; 
	return kvp;
}

pair<int,int> LinkedList::getNode(LinkedListNode* node) {
	
	if (node == nullptr) {
		cout << "Not a valid address" << endl;
		return make_pair(-1,-1);
	}

	LinkedListNode * prevNode = node->prev;
	LinkedListNode * nextNode = node->next;

	prevNode->next = nextNode;
	if (nextNode != nullptr)
		nextNode->prev = prevNode;
	else {
		tail = prevNode;
	}
	
	node->next = head;
	node->prev = nullptr;
	head = node;

	return node->data;
}

void LinkedList::update(int key, int val) {
	LinkedListNode *node = head;
	if (node->data.first == key) {
		node->data.second = val;
	}
	else {
		cout << "Node with key = " << key << "couldn't be found" << endl;
	}
}

void LinkedList::display() {
	LinkedListNode *tmp = head;
	while (tmp != nullptr) {
		cout << "{" <<tmp->data.first << "," << tmp->data.second << "}" <<'\t';
		tmp = tmp->next;
	}
	cout << endl;
}
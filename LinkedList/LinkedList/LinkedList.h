#pragma once
class LinkedListNode {
public:
	LinkedListNode(int val) : data(val), next(nullptr) {

	}
	~LinkedListNode() {

	}
	int data;
	LinkedListNode *next;
};

class LinkedList {
	LinkedListNode *head;
	LinkedListNode *tail;
public:
	LinkedList();
	LinkedList(const vector<int>& num);
	~LinkedList();

	inline LinkedListNode * getRoot() {
		return head;
	}
	void insert(const int& val);
	void display(LinkedListNode *root);
	void reverse(LinkedListNode *root);
	bool GetNthNodefromEnd(LinkedListNode *root, const int& n , int& output);
	bool GetNthNodefromEnd2(LinkedListNode *root, const int& n, int& output);
	bool GetNthNodefromEnd3(LinkedListNode *root, const int& n, int& output);
	bool findNthNodeFromEndUsingRecursion(LinkedListNode *root, const int& n, int& output);
	int getSize(LinkedListNode *root);
	bool createLoop(LinkedListNode *root, const int& toNode);
	bool isLoopInLinkedList(LinkedListNode* root);
	bool isLoopInLinkedList2(LinkedListNode* root);
	bool FindStartOfTheLoop(LinkedListNode *root, int &output, int &lengthOfLoop);
	bool findMiddleOfLinkedList(LinkedListNode *root, int &out);
	void DisplayLinkedListFromEnd(LinkedListNode* root);
	int IsLinkedListEvenOrOdd(LinkedListNode* root);
	void ConvertToEvenFollowedByOddElementsSequence(LinkedListNode *root);
	void ReverseLinkedListInPairs(LinkedListNode *root);
};
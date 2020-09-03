// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <unordered_map>
#include <unordered_set>
LinkedList::LinkedList() : head(nullptr) {

}

LinkedList::LinkedList(const vector<int>& num) {
	//Initialize LinkedList from vector of ints.
	for (const auto& i : num)
		insert(i);
}

LinkedList::~LinkedList() {

}

void LinkedList::insert(const int& val) {
	LinkedListNode *newNode = new LinkedListNode(val);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	
	tail->next = newNode;
	tail = newNode;

}

void LinkedList::display(LinkedListNode *root) {
	if (root == nullptr) {
		cout << "Linked List is empty" << endl;
		return;
	}

	while (root != nullptr) {
		cout << root->data << "\t";
		root = root->next;
	}
	cout << endl;
}

void LinkedList::reverse(LinkedListNode *root) {
	LinkedListNode *p=root, *q=p, *r=nullptr;
	tail = p;
	while (q != nullptr) {
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	head = r;
}

int LinkedList::getSize(LinkedListNode *root) {
	if (root == nullptr) {
		cout << "Linked List is empty" << endl;
		return 0;
	}

	int count = 0;
	while (root != nullptr) {
		++count;
		root = root->next;
	}
	return count;
}

bool LinkedList::findNthNodeFromEndUsingRecursion(LinkedListNode *root,const int& n , int& output) {
	static int i = getSize(root);

	if (root == nullptr) {
		return false;
	}

	if (i-- == n) {
		output = root->data;
		return true;
	}
	bool ret = findNthNodeFromEndUsingRecursion(root->next,n,output);
	return ret;

}

bool LinkedList::GetNthNodefromEnd(LinkedListNode *root,const int& n ,int& output) {
	//Problem 3: Using HashTable. Time Complexity : O(n) , Space Complexity : O(n)
	if (root == nullptr) {
		return false;
	}
	unordered_map<int, LinkedListNode *> uMap;
	int count = 0;
	while (root != nullptr) {
		uMap[++count] = root;
		root = root->next;
	}
	if (count < n) {
		cout << "The number of nodes in linked list is less than the nth node to be fetched" << endl;
		return false;	
	}

	//Nth node from end of the linked list will be at position  (count-n)+1
	output = uMap[count - n + 1]->data;
	return true;

}

bool LinkedList::GetNthNodefromEnd2(LinkedListNode *root, const int& n, int& output) {
	//Problem 4: Time Complexity : O(n) , Space Complexity : O(1)
	if (root == nullptr) {
		cout << "Linked List empty" << endl;
		return false;
	}
	int len = getSize(root);
	if (len < n) {
		cout << "The number of nodes in linked list is less than the nth node to be fetched" << endl;
		return false;
	}
	int count = 1;
	while (count != len - n + 1) {
		root = root->next;
		++count;
	}
	output = root->data;
	return true;
}

bool LinkedList::GetNthNodefromEnd3(LinkedListNode *root, const int& n, int& output) {
	//Problem 5: Using two pointers to scan in one pass. Time Complexity : O(n), Space Complexity  : O(1)
	if (root == nullptr) {
cout << "Linked List empty" << endl;
return false;
	}
	LinkedListNode *pTemp = root, *pNthNode = root;
	int count = n;
	while (pTemp != nullptr) {
		if (count != 0) {
			pTemp = pTemp->next;
			count--;
		}
		else {
			pTemp = pTemp->next;
			pNthNode = pNthNode->next;
		}
	}
	if (count != 0) {
		cout << "The number of nodes in linked list is less than the nth node to be fetched" << endl;
		return false;
	}
	output = pNthNode->data;
	return true;

}

//Create a loop in the linked list.

bool LinkedList::createLoop(LinkedListNode *root, const int& toNode) {
	if (root == nullptr) {
		cout << "List is empty" << endl;
		return false;
	}

	int len = getSize(root);
	if (len < toNode) {
		cout << "The length of the linked list is lesser than the toNode" << endl;
		return false;
	}

	int count = 1;
	while (toNode != count) {
		root = root->next;
		++count;
	}
	tail->next = root;
}

bool LinkedList::isLoopInLinkedList(LinkedListNode* root) {
	//Using two pointers. Time Complexity: O(n), Space Complexity : O(1)
	LinkedListNode *slowptr = root, *fastptr = root;
	while (slowptr && fastptr) {
		fastptr = fastptr->next;
		if (slowptr == fastptr)
			return true;
		if (fastptr == nullptr)
			return false;
		fastptr = fastptr->next;
		if (slowptr == fastptr)
			return true;
		slowptr = slowptr->next;
	}

	return false;
}

bool LinkedList::isLoopInLinkedList2(LinkedListNode* root) {
	//Using hashtable. Time Complexity : O(n), Space Complexity: O(n)
	unordered_set<LinkedListNode *> uSet;
	while (root != nullptr) {
		if (uSet.find(root) == uSet.end()) {
			uSet.insert(root);
		}
		else {
			return true;
		}

	}
	return false;
}

bool LinkedList::FindStartOfTheLoop(LinkedListNode *root, int &output,int &lengthOfLoop) {
	LinkedListNode *slowptr = root, *fastptr = root;
	bool isLoopPresent = false;
	while (slowptr && fastptr) {
		fastptr = fastptr->next;
		if (slowptr == fastptr) {
			isLoopPresent = true;
			break;
		}
		if (fastptr == nullptr) {
			isLoopPresent = false;
			break;
		}
		fastptr = fastptr->next;
		if (slowptr == fastptr) {
			isLoopPresent = true;
			break;
		}
		slowptr = slowptr->next;
	}

	if(isLoopPresent){
		int count = 0;
		slowptr = root;
		while (slowptr != fastptr) {
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			++count;
		}
		output = slowptr->data;
		lengthOfLoop = count;
	}

	return isLoopPresent;
}

bool LinkedList::findMiddleOfLinkedList(LinkedListNode *root,int &out) {
	//Using two pointers. Time Complexity : O(n), Space Complexity: O(1)
	if (root == nullptr) {
		cout << "LinkedList is empty" << endl;
		return false;
	}

	LinkedListNode *fastptr = root, *slowptr = root;
	while (fastptr != nullptr) {
		fastptr = fastptr->next;
		if (fastptr == nullptr) {
			out = slowptr->data;
			return true;
		}
		fastptr = fastptr->next;
		if (fastptr == nullptr) {
			out = slowptr->data;
			return true;
		}
		slowptr = slowptr->next;
	}

	return false;
}


void LinkedList::DisplayLinkedListFromEnd(LinkedListNode* root){
	if (root == nullptr)
		return;
	DisplayLinkedListFromEnd(root->next);
	cout << root->data << '\t';
}

int LinkedList::IsLinkedListEvenOrOdd(LinkedListNode* root) {

	while (root && root->next) {
		root = root->next->next;
	}

	if (root == nullptr)
		return 1; // 1 denotes even
	else
		return 0; //0 denotes odd;

}

void LinkedList::ConvertToEvenFollowedByOddElementsSequence(LinkedListNode *root) {
	 //  Input : 10 -> 24 -> 12 -> 25 -> 78 -> 1 -> 2 -> 3 
	 //	 Output: 10 -> 24 -> 12 -> 78 -> 25 -> 1 -> 2 -> 3
	 //Problem 43. Time Complexity : O(n), Space Complexity : O(1)
	LinkedListNode *local_odd_head = nullptr, *local_even_head = nullptr;
	LinkedListNode *local_even_tail = nullptr, *local_odd_tail = nullptr;
	LinkedListNode *tmp = root;
	while (tmp != nullptr) {
		if (tmp->data % 2 == 0) {
			if (local_even_head == nullptr) {
				local_even_head = tmp;	
				local_even_tail = tmp;
			}
			else {
				local_even_tail->next = tmp;
			}
			local_even_tail = tmp;
			tmp = tmp->next;
			local_even_tail->next = nullptr;
		}
		else {
			if (local_odd_head == nullptr) {
				local_odd_head = tmp;
				local_odd_tail = tmp;
			}
			else {
				local_odd_tail->next = tmp;
			}
			local_odd_tail = tmp;
			tmp = tmp->next;
			local_odd_tail->next = nullptr;
		}
	}
	local_even_tail->next = local_odd_head;
	head = local_even_head;
	tail = local_odd_tail;

}

void LinkedList::ReverseLinkedListInPairs(LinkedListNode *root) {

}
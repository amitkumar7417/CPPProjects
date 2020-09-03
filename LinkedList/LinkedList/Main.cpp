#include "stdafx.h"
#include "LinkedList.h"

int main()
{
	vector<int> num = { 10,24,12,25,78,1,2,3 };
	LinkedList list(num);
	cout << "Displaying newly created linked list" << endl;
	list.display(list.getRoot());
	
	cout << "Reversing the linked list" << endl;
	list.reverse(list.getRoot());
	list.display(list.getRoot());

	//Reversing the linked list again to restore original linked list.
	cout << "Reversing the linked list again to restore original linked list" << endl;
	list.reverse(list.getRoot());
	list.display(list.getRoot());

	cout << "Find Nth Node from the end of a linked list." << endl;
	int nthNodeFromEnd = 3;
	int nthNode;
	bool foundNthNode = list.findNthNodeFromEndUsingRecursion(list.getRoot(), nthNodeFromEnd, nthNode);
	if (foundNthNode)
		cout << "Node at position " << nthNodeFromEnd << " from end is = " << nthNode << endl;
	else
		cout << "Node at position " << nthNodeFromEnd << " could not be found" << endl;

	foundNthNode = list.GetNthNodefromEnd(list.getRoot(), nthNodeFromEnd, nthNode);
	if (foundNthNode)
		cout << "Node at position " << nthNodeFromEnd << " from end is = " << nthNode << endl;
	else
		cout << "Node at position " << nthNodeFromEnd << " could not be found" << endl;

	foundNthNode = list.GetNthNodefromEnd2(list.getRoot(), nthNodeFromEnd, nthNode);
	if (foundNthNode)
		cout << "Node at position " << nthNodeFromEnd << " from end is = " << nthNode << endl;
	else
		cout << "Node at position " << nthNodeFromEnd << " could not be found" << endl;

	foundNthNode = list.GetNthNodefromEnd3(list.getRoot(), nthNodeFromEnd, nthNode);
	if (foundNthNode)
		cout << "Node at position " << nthNodeFromEnd << " from end is = " << nthNode << endl;
	else
		cout << "Node at position " << nthNodeFromEnd << " could not be found" << endl;
	
	bool isLoopPresent = list.isLoopInLinkedList(list.getRoot());
	cout << "Is loop present in the linked list : " << isLoopPresent << endl;

	/*
	//Create Loop
	bool isLoopCreated = list.createLoop(list.getRoot(),3);
	//list.display(list.getRoot());
	
	isLoopPresent = list.isLoopInLinkedList(list.getRoot());
	cout << "Is loop present in the linked list : " << isLoopPresent << endl;

	isLoopPresent = list.isLoopInLinkedList2(list.getRoot());
	cout << "Is loop present in the linked list : " << isLoopPresent << endl;
	*/

	/*  Not working fine, Going in infinite loop
	int firstNodeInLoop;
	int lengthOfLoop;
	isLoopPresent = list.FindStartOfTheLoop(list.getRoot(), firstNodeInLoop, lengthOfLoop);
	if (isLoopPresent)
		cout << "First node in the loop is : " << firstNodeInLoop << "The length of the loop is"<< lengthOfLoop  << endl;
	*/
	int middleNode;
	bool isMiddleNodeFound = list.findMiddleOfLinkedList(list.getRoot(), middleNode);
	if (isMiddleNodeFound)
		cout << "Middle node of the linked list points to = " << middleNode << endl;

	list.DisplayLinkedListFromEnd(list.getRoot());
	cout << endl;

	cout << "Is Linked List Even(1) or Odd(0) : " << list.IsLinkedListEvenOrOdd(list.getRoot()) << endl;

	list.ConvertToEvenFollowedByOddElementsSequence(list.getRoot());
	cout << "Display the list after appending odd elements at the end of even elements" << endl;
	list.ConvertToEvenFollowedByOddElementsSequence(list.getRoot());
	list.display(list.getRoot());

	//Reverse linked list in pair
	cout << "Reversing a linked list in pair" << endl;
	list.ReverseLinkedListInPairs(list.getRoot());
	list.display(list.getRoot());

	return 0;
}
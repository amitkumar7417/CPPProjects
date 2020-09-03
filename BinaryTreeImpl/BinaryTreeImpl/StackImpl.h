#pragma once

template <typename T>
class StackNode {
public:
	StackNode(T val) : data(val), next(nullptr) {

	}
	T data;
	StackNode *next;
};

template <typename T>
class Stack {
private:
	StackNode<T> * head;
	static Stack<T> *m_stack;
public:
	Stack() : head(nullptr) {

	}
	static Stack<T> * CreateStack() {
		m_stack =  new Stack();
		return m_stack;
	}
	T top();
	T pop();
	void push(T val);
	bool isEmpty();
	int stackSize();
	void DeleteStack();
};

template <typename T>
Stack<T> *Stack<T>::m_stack = nullptr;

template <typename T>
T Stack<T>::top() {
	if (head != nullptr)
		return head->data;
}
template <typename T>
T Stack<T>::pop() {
	T val = nullptr;
	if (head != nullptr) {
		StackNode<T> *tmp = head;
		val = head->data;
		head = head->next;
		delete tmp;
	}
	return val;
}

template <typename T>
void Stack<T>::push(T val) {
	StackNode<T> *newNode = new StackNode<T>(val);
	if (head == nullptr)
		head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}

template <typename T>
bool Stack<T>::isEmpty() {
	return stackSize() > 0 ? false : true;
}

template <typename T>
int Stack<T>::stackSize() {
	int count = 0;
	StackNode<T> *tmp = head;
	while (tmp != nullptr) {
		++count;
		tmp = tmp->next;
	}
	return count;
}

template <typename T>
void Stack<T>::DeleteStack() {
	//Iterate through stack entries and delete one by one.
	StackNode<T> *currNode, *tmp = head;
	while (tmp != nullptr) {
		currNode = tmp;
		tmp = tmp->next;
		delete(currNode);
	}
	if (m_stack != nullptr) {
		delete m_stack;
	}
}
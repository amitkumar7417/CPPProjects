#pragma once

template <typename  T>
class QueueNode {
public:
	QueueNode(T val) : data(val), next(nullptr) {

	}
	T data;
	QueueNode *next;
};

template <typename  T> 
class Queue {
private:
	QueueNode<T> * head;
	static Queue<T> *m_queue;
public:
	Queue<T>() : head(nullptr) {

	}
	static Queue<T> * CreateQueue() {
		m_queue = new Queue();
		return m_queue;
	}
	T peek();
	T front();
	void add(T val);
	bool isEmpty();
	int queueSize();
	void DeleteQueue();
};

template <typename  T>
Queue<T> * Queue<T>::m_queue = nullptr;

template <typename  T>
T Queue<T>::peek() {
	if (head != nullptr)
		return head->data;
	else
		return nullptr;
}
template <typename  T>
T Queue<T>::front() {
	if (head != nullptr) {
		QueueNode<T> *nxtNode = head->next;
		T val = head->data;
		delete(head);
		head = nxtNode;
		return val;
	}
}

template <typename  T>
void Queue<T>::add(T val) {
	//Add to the end of the queue list.
	QueueNode<T> *newNode = new QueueNode<T>(val);
	if (head == nullptr)
		head = newNode;
	else {
		QueueNode<T> *tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

template <typename  T>
bool Queue<T>::isEmpty() {
	return queueSize() > 0 ? false : true;
}

template <typename  T>
int Queue<T>::queueSize() {
	QueueNode<T> *tmp = head;
	int count = 0;
	while (tmp != nullptr) {
		++count;
		tmp = tmp->next;
	}
	return count;

}

template <typename  T>
void Queue<T>::DeleteQueue() {
	//Iterate through stack entries and delete one by one.
	QueueNode<T> *currNode, *tmp = head;
	while (tmp != nullptr) {
		currNode = tmp;
		tmp = tmp->next;
		delete(currNode);
	}
	if (m_queue != nullptr) {
		delete m_queue;
	}
}
#include "stdafx.h"
#include "LRUImpl.h"

int LRUImpl::get(int key) {
	//Check if the key exits in the hashtable first
	if (uMap.find(key) != uMap.end()) {
		cout << "Key is present in the cache memory." << endl;
		//If key exists in the hashtable then get it and append it to the top of the list
		int val = list->getNode(uMap[key]).second;
		return val;
	}
	else {
		cout << "Key is not present in the cache memory. Cache Miss" << endl;
		//If key doesn't exists then add it to the cache,list
		if (count == size) {
			pair<int, int> deletedNode = list->deleteTailNode();
			uMap.erase(deletedNode.first);
			count--;
		}
		LinkedListNode * newNode = list->insertAtFront(make_pair(key,0));
		uMap[key] = newNode;
		count++;
		return 0;
	}
	
}


void LRUImpl::put(int key, int val) {
	//Update val for the key;
	list->update(key,val);
}

void LRUImpl::cacheDisplay() {
	list->display();
}
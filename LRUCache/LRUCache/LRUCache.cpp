#include "stdafx.h"
#include "LRUCache.h"

int LRUCache::get(int key) {
	if (uMap.find(key) == uMap.end()) {
		//Key is not present in the cache memory.
		if (cacheSize == cacheList.size()) {
			//Remove element corresponing to the end of the list from hash table
			auto lastElementIter = cacheList.back();
			auto lastElementKey = lastElementIter->getKey();
			uMap.erase(lastElementKey);
			//Remove element from the end of the list
			cacheList.pop_back();
		}
		Node *n = new Node(key, 0);
		cacheList.push_front(n);
		uMap[key] = cacheList.begin();
		return n->getValue();
	}
	else {
		//Key is already present in the cache memory
		auto itemIter = uMap[key];
		//Bring it to the front of the list.
		auto existingNode = *itemIter;
		cacheList.erase(itemIter);
		cacheList.push_front(existingNode);
		return existingNode->getValue();
	}
}

int LRUCache::accessCache(int key) {
	return get(key);
}

int LRUCache::updateCache(int key, int value) {
	auto iter = uMap[key];
	(*iter)->setValue(value);
	return 0;
}

void LRUCache::displayCache() {
	for (auto i : cacheList) {
		cout << "{" << i->getKey() << "," << i->getValue() << "}";
	}
	cout << endl;
}
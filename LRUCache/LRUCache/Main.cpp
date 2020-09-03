#include "stdafx.h"
#include "LRUCache.h"
int main() {
	LRUCache lCache(5);
	lCache.accessCache(1);
	lCache.updateCache(1, 12);
	lCache.accessCache(2);
	lCache.updateCache(2, 24);
	lCache.accessCache(3);
	lCache.updateCache(3, 36);
	lCache.accessCache(4);
	lCache.updateCache(4, 48);
	lCache.accessCache(5);
	lCache.updateCache(5, 60);
	lCache.displayCache();
	lCache.accessCache(6);
	lCache.updateCache(6, 72);
	lCache.displayCache();
	lCache.accessCache(2);
	lCache.displayCache();
	return 0;
}


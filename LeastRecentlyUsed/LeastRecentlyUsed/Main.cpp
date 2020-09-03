// LeastRecentlyUsed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LRUImpl.h"

int main()
{
	LRUImpl impl(5);
	impl.get(1);
	impl.put(1, 4);
	impl.get(2);
	impl.put(2, 5);
	impl.get(3);
	impl.put(3, 7);
	impl.get(4);
	impl.put(4, 10);
	impl.get(5);
	impl.put(5, 12);
	impl.cacheDisplay();
	impl.get(1);
	impl.cacheDisplay();
	impl.get(6);
	impl.cacheDisplay();
    return 0;
}


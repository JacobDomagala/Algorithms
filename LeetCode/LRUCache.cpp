#include <list>
#include <map>

using namespace std;

/*
	Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

	The cache is initialized with a positive capacity.

	-----------------------------------EXAMPLE-----------------------------------

	LRUCache cache = new LRUCache( 2 ); // LRUCache with capacity of 2

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4

*/

class LRUCache {
	using HashIter = list<pair<int, int>>::iterator;
	int m_capacity;

	list<pair<int, int>> m_list;
	map<int, HashIter> m_hash;

public:
	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		auto it = m_hash.find(key);

		if (it == m_hash.end()) {
			return -1;
		}

		m_list.splice(m_list.begin(), m_list, m_hash[key]);
		return m_hash[key]->second;
	}

	void put(int key, int value) {
		if (get(key) != -1) {
			m_hash[key]->second = value;
			return;
		}

		if (m_hash.size() >= m_capacity) {
			auto valLast = m_list.back().first;
			m_list.pop_back();
			m_hash.erase(valLast);
		}

		m_list.emplace_front(key, value);
		m_hash[key] = m_list.begin();
	}
};
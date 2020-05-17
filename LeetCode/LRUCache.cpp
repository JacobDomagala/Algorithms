#include <list>
#include <map>

using namespace std;

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
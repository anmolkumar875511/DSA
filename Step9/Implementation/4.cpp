#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        auto node = mp[key];
        int value = node->second;

        dll.erase(node);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == capacity) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};


int main() {
    LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}
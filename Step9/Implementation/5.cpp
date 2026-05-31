#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LFUCache {
private:
    struct Node {
        int value;
        int freq;
    };

    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> cache;

    unordered_map<int, list<int>> freqList;

    unordered_map<int, list<int>::iterator> pos;

    void updateFreq(int key) {
        int freq = cache[key].second;

        freqList[freq].erase(pos[key]);

        if(freqList[freq].empty()) {
            freqList.erase(freq);

            if(minFreq == freq)
                minFreq++;
        }

        cache[key].second++;

        freqList[freq + 1].push_back(key);

        auto it = freqList[freq + 1].end();
        --it;

        pos[key] = it;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        updateFreq(key);

        return cache[key].first;
    }

    void put(int key, int value) {
        if(capacity == 0)
            return;

        if(cache.find(key) != cache.end()) {
            cache[key].first = value;
            updateFreq(key);
            return;
        }

        if(cache.size() == capacity) {
            int evictKey = freqList[minFreq].front();

            freqList[minFreq].pop_front();

            if(freqList[minFreq].empty())
                freqList.erase(minFreq);

            cache.erase(evictKey);
            pos.erase(evictKey);
        }

        cache[key] = {value, 1};

        freqList[1].push_back(key);

        auto it = freqList[1].end();
        --it;

        pos[key] = it;

        minFreq = 1;
    }
};


int main() {
    LFUCache cache = LFUCache(2);
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
#include<vector>
#include<list>
#include<unordered_map>
using std::list;
using namespace std;

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private: 
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if(it == cacheMap.end()){
            return -1;
        }

        auto node = *(it->second);
        cacheList.erase(it->second);

        cacheList.push_front(node);
        cacheMap[key] = cacheList.begin();

        return node.second;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);

        if(it != cacheMap.end()){
            cacheList.erase(it->second);
        }
        else if(cacheList.size() == capacity){
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }

        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


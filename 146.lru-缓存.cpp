#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    list<pair<int, int>> cacheList;

    // 存key, value
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){ // 找不到对应key时find函数会返回尾指针值
            return -1;
        }
        int value = cacheMap[key]->second; 
        // cacheMap[key] 是 链表迭代器， first是key，second是value
        // 接下来需要把value移到队头（刚刚访问了）
        cacheList.erase(cacheMap[key]);
        cacheList.push_front({key, value});     
        cacheMap[key] = cacheList.begin(); // 更新  
        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){ // 找不到对应key时
            if(cacheMap.size()==capacity){
                int popkey = cacheList.back().first;
                cacheMap.erase(popkey);
                cacheList.pop_back();

                cacheList.push_front({key, value});
                cacheMap[key] = cacheList.begin();
            } else{
                cacheList.push_front({key, value});
                cacheMap[key] = cacheList.begin();
            }
        } else{
            cacheList.erase(cacheMap[key]);
            cacheList.push_front({key, value});       
            cacheMap[key] = cacheList.begin(); 
            // 已存在的情况下，删除迭代器然后直接在队头塞新数值
            // 因为合法不需要考虑capacity
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){
    LRUCache lru(2); // 容量为2

    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // 返回1
    lru.put(3, 3); // 淘汰key=2
    std::cout << lru.get(2) << std::endl; // 返回-1
    lru.put(4, 4); // 淘汰key=1
    std::cout << lru.get(1) << std::endl; // 返回-1
    std::cout << lru.get(3) << std::endl; // 返回3
    std::cout << lru.get(4) << std::endl; // 返回4
}


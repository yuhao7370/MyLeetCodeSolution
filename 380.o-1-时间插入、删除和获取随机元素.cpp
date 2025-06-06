/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(dict.count(val)){
            return false;
        }
        nums.push_back(val);
        dict[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!dict.count(val)){
            return false;
        }
        int index = dict[val];
        int tmp = nums.back();
        nums[index] = tmp;
        dict[tmp] = index;
        nums.pop_back();
        dict.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> dict;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end


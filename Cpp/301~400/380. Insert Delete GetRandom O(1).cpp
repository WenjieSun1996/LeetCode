class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet(): sz(0) {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val] = sz++;
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;
        int pos = m[val];
        m[nums[--sz]] = pos;
        nums[pos] = nums[sz];
        m.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % sz];
    }
    
private:
    unordered_map<int, int> m;  // <number, pos>
    int sz;                     // the size of nums
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

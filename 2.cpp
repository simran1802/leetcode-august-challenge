class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> myhash;
    MyHashSet() {
        myhash.resize(83);
    }
    
    void add(int key) {
        int val = key%83;
        for(int a : myhash[val])
        {
            if(a==key)
            {
                return;
            }
        }
        myhash[val].push_back(key);
    }
    
    void remove(int key) {
        int val = key%83;
        for(int s=0; s<myhash[val].size();s++)
        {
            if(myhash[val][s]==key)
            {
                myhash[val].erase(myhash[val].begin()+s);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int val = key%83;
        for(int a : myhash[val])
        {
            if(a==key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

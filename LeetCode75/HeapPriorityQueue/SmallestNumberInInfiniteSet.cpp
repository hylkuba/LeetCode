#include <set>

class SmallestInfiniteSet {
    std::set<int> nums;

public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            nums.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = *nums.begin();
        nums.erase(smallest);

        return smallest;
    }
    
    void addBack(int num) {
        nums.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
class SmallestInfiniteSet {
    multiset<int>pq;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            pq.insert(i);
        }
    }
    
    int popSmallest() {
        int a = *pq.begin();
        pq.erase(*pq.begin());
        return a;
    }
    
    void addBack(int num) {
        pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
class SmallestInfiniteSet {
    multiset<int>pq;
    int curr = 1;

public:
    SmallestInfiniteSet() {
        // for(int i = 1; i <= 1000; i++){
        //     pq.insert(i);
        // }
    }
    
    int popSmallest() {
        int x;
        if(pq.size()){
            x = *pq.begin(); 
            pq.erase(x);
        }
        else{
            x = curr;
            curr++;
        }
        return x;
    
        // int a = *pq.begin();
        // pq.erase(*pq.begin());
        // return a;
    }
    
    void addBack(int num) {
        if(num < curr){
            pq.insert(num);
            // curr = num;
            }
        // else if(num<*pq.begin())
        //     pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
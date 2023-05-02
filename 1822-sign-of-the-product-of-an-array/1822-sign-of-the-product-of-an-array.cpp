class Solution {
public:
    int arraySign(vector<int>& nums) {
        int i = 1;
        for(auto n:nums){
            if(i == 1 and n*i < i) i = -1; 
            else if(i == -1 and n*i>0) i = 1;
            
            if(n == 0) return 0;
        }
        return i;
    }
};
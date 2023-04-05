class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0; 
        int max = nums[0];
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            int temp = ceil(1.0*sum/(i+1));
            if(temp>max) max = temp;
        }
        return max;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return 0;
        vector<int>nums1(nums);
        vector<int>nums2(nums);

        int res = -1;
        for(int i = 1, j = n-2; i <n or j>=0; i++, j--){
            nums1[i]+=nums1[i-1];
            nums2[j]+=nums2[j+1];
        }
        
        for(int i = 0; i < n; i++){
            if(nums1[i]==nums2[i]) return i; 
        }
        return res;
    }
};
class Solution {
public:

    int binarySearch(vector<int>&nums, int l, int h, int target){
        if(l>h) return -1;
        int mid = l + (h-l)/2;
        if(target ==nums[mid]) return mid;
        else if(target > nums[mid]) return binarySearch(nums, mid+1, h, target);
        else return binarySearch(nums, 0, mid-1, target);
        // return -1;
    }

    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        vector<int>v;
        for(int i = 0; i < nums.size(); i++){
            int f = target - nums[i];
            auto itr = mp.find(f);
            if(itr!=mp.end() and itr->second!=i){
                v.push_back(i);
                v.push_back(itr->second);
                break;
            }
        }
        return v;

    }
};
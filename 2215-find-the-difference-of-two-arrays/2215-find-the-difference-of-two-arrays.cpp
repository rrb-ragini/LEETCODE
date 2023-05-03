class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1, s2;

        vector<int>v1, v2;
        for(auto n:nums1) s1.insert(n);
        for(auto n:nums2) s2.insert(n);
        
        for(auto s:s1)
            if(s2.find(s) == s2.end())v1.push_back(s);
        for(auto s:s2)
            if(s1.find(s) == s1.end())v2.push_back(s);
        return {v1, v2};
        
    }
};
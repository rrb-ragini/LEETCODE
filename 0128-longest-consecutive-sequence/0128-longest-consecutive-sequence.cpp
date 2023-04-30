class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++)
            st.insert(nums[i]); 
    
        for(auto s:st){
            if(st.find(s-1)==st.end()){
                int currentNum = s;
                int currentStreak = 1;
                
                while(st.find(currentNum+1)!=st.end()) {currentStreak++; currentNum++;}
                maxi = max(maxi, currentStreak);
            }
        }
        return maxi;
    }
};
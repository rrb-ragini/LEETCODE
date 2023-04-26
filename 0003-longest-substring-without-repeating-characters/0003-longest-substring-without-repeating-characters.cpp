class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        
        int count[128] = {};
        int l = 0, r = 0;
        int res = 0;
        while(r < s.length()){
            count[s[r]]++;
            r++;
            if(*max_element(count, count + 128) > 1){
                // *l--;
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l);
        }
        return res;
    }
};
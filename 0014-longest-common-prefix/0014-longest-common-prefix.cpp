class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=1) return strs[0];
        // string s = strs[0];
        int n = strs.size();
        int prefix = strs[0].size();
        for(int i = 1; i < n; i++){
            int j;
            for(j = 0; j < min(strs[i-1].size(), strs[i].size());){
                if(strs[i-1][j] == strs[i][j]) j++; 
                else break;
            }
            prefix = min(j, prefix);
        }
        return strs[0].substr(0, prefix);
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int h = 0, t = 0, result = 0, cnt[26] = {};
        
        for(h = 0; h < s.size(); h++){
            cnt[s[h] - 'A']++;
            while(h-t + 1 - *max_element(cnt, cnt+26)>k){
                cnt[s[t] - 'A']--;
                t++;
            }
            result = max(result, h-t+1);
        }
        return result;
        
    }
};
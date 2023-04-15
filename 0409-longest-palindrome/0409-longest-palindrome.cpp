class Solution {
    map<char, int>mp;
public:
    int longestPalindrome(string s) {
        for(char c: s){
            mp[c]++;
        }

        int even=0;
        int odd=0;
        for(auto m:mp){
            if(m.second%2==0) even+=m.second;
            else {
                odd=max(odd, m.second);
                even+=m.second-1;
            }
        }
        if(odd>0){even = even+1;}
        return even;
    }
};
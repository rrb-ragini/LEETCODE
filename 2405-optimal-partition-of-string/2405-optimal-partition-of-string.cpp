class Solution {
public:
    int partitionString(string s) {
        int count = 0; 
        map<char, int>mp;
        for(auto ch:s){
            if(mp[ch]>=1) {count++; mp.clear();}
            mp[ch]++;
        }
        return count+1;
    }
};
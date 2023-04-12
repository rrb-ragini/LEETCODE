class Solution {
    unordered_map<char, char>mp1;
    unordered_map<char, bool>mp2;
    // static bool cmp(pair<char, int>a, pair<char, int>b){
    //     return a.second<b.second;
    // }
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        char a, b;
        for(int i = 0; i < s.size(); i++){
            a = s[i];
            b = t[i];
            if(mp1.find(a)!=mp1.end() and mp1[a]!=b) return false;
            else if(mp1.find(a)==mp1.end() and mp2[b]==true) return false;
            else{
                mp1[a]=b; mp2[b]=true;
            }
        }
        return true;
    }
};
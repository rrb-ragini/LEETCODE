class Solution {
    bool checkVowel(char s){
        if(s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u') return  true;
        else return false;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxi = 0;
        for(int i = 0; i < k; i++)  
            if(checkVowel(s[i])) maxi++;
        int count = maxi;
        for(int i = k; i < n; i++){
            if(checkVowel(s[i])) maxi++;
            if(checkVowel(s[i-k])) maxi--;
            count = max(maxi, count);
        }
        return count;
    }
};
class Solution {
    map<string, int>mp;
public:
    int result = 0;
    int romanToInt(string s) {
        int n = s.size();
        mp["I"] = 1;
        mp["IV"] = 4;
        mp["V"] = 5;
        mp["IX"] = 9;
        mp["X"] = 10;
        mp["XL"] = 40;
        mp["L"] = 50;
        mp["XC"] = 90;
        mp["C"] = 100;
        mp["CD"] = 400;
        mp["D"] = 500;
        mp["CM"] = 900;
        mp["M"] = 1000;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'I'){
                if(i+1 < n and s[i+1] =='V') {result += 4; i++;}
                else if(i+1 < n and s[i+1] =='X') {result += 9;i++;}
                else result++;
            }
            else if(s[i] == 'V') result += 5;
            
            else if(s[i] == 'X') {
                if(i+1 < n and s[i+1] == 'L') {result += 40;i++;}
                else if(i+1 < n and s[i+1] == 'C') {result += 90;i++;}
                else result+= 10;
            }
            else if(s[i] == 'L') result += 50;
            else if(s[i] == 'C'){
                if(i+1 < n and s[i+1] == 'D') {result+=400;i++;}
                else if(i+1 < n and s[i+1] == 'M') {result += 900;i++;}
                else result+=100;
            }
            else if(s[i] == 'D') result+=500;
            else if(s[i] == 'M') result+=1000;
        }
        return result;
    }
};
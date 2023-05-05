class Solution {
    Boolean vowelcheck(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
        else return false;
    }
    public int maxVowels(String s, int k) {
        int n = s.length();
        int maxi = 0;
        for(int i = 0; i < k; i++)
            if(vowelcheck(s.charAt(i))) maxi++;
               
        int count = maxi;
        for(int i = k; i < n; i++){
            if(vowelcheck(s.charAt(i))) maxi++;
            if(vowelcheck(s.charAt(i-k))) maxi--;
            count = Math.max(count, maxi);
        }
        return count;
    }
}
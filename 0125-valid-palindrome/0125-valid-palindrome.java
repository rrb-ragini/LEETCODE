class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int n = s.length() - 1;
        int i = 0;
        while(i < n){
            while(!Character.isLetterOrDigit(s.charAt(i)) && i < n) i++;
            while(!Character.isLetterOrDigit(s.charAt(n)) && n > i) n--;
            if(i >= n) break;
            if(s.charAt(i) != s.charAt(n)) return false;
            i++; n--;            
        }
        return true;
    }
} 
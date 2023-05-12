class Solution {
    int n;
    int[][] question;
    long[] v; 
    long solve(int i){
        if(i >= n) return 0;
        if(v[i]!=0)
            return v[i];
        //count
        long count = (question[i][0] + solve(i + question[i][1] + 1));
        
        //skip
        long skip = solve(i+1);
        
        return v[i] = Math.max(count, skip);
    }
    
    public long mostPoints(int[][] questions) {
        n = questions.length;
        question = questions;
        v = new long[n]; 
        return solve(0);
    }
}
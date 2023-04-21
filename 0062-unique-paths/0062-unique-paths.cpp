class Solution {
    vector<vector<int>>dp;
    
    int solve(int m, int n){
        if(m==0 and n==0)  return 1;
        if(m<0 or n <0) return 0;

        if(dp[m][n]!=0) return dp[m][n];

        return dp[m][n] += solve(m-1, n) + solve(m, n-1);
    }
    
public:
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        return solve(m-1, n-1);
    }
};
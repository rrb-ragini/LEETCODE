class Solution {
    string a, b;
    vector<vector<int>>dp;
    int LCS(int idx1, int idx2){
        if(idx1 < 0 or idx2 < 0) return 0;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(a[idx1] == b[idx2]) return dp[idx1][idx2] = 1 + LCS(idx1 - 1, idx2 - 1);
        
        return dp[idx1][idx2] = max(LCS(idx1-1, idx2), LCS(idx1, idx2-1));
    }
    
public:
    int minInsertions(string s) {
        int n = s.length();
        a = s;
        b = s;
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        reverse(b.begin(), b.end()); 
        return n - LCS(n-1, n-1);
    }
};
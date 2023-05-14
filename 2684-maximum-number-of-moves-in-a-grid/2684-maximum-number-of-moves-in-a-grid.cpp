class Solution {
    vector<vector<int>>dp;
    vector<vector<int>>g;
    int n, m;
    int solve(int i, int j){
        if(i < 0 or i >= n or j < 0 or j >= m) return 0;
        
        if(dp[i][j]!=0) return dp[i][j];
        
        int a = 0, b = 0, c = 0;
        
        if(i - 1 >= 0 and j + 1 < m)
            if(g[i-1][j+1] > g[i][j])
                a = solve(i - 1, j + 1);
        
        if(j + 1 < m)
            if(g[i][j+1] > g[i][j])
                b = solve(i, j + 1);
        
        if(i + 1 < n and j + 1 < m)
            if(g[i+1][j+1] > g[i][j])
                c = solve(i + 1, j + 1);
        
        return dp[i][j] = (1 + max(a, max(b, c))); //dp store condition 
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        g = grid;
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        int maxi = 0;
        for(int i = 0; i < n; i++){
                if(dp[i][0]==0){
                    maxi = max(maxi, solve(i, 0));
            }
        }
        return --maxi;
    }
};
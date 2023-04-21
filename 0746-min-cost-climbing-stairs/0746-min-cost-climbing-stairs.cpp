class Solution {
    int n;
    vector<int>costList;
    vector<int>dp;
    int solve(int i){
        if(i == 0 or i == 1) return costList[i];
            
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = costList[i] + min(solve(i-1), solve(i-2));
    
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        costList = cost;
        dp = vector<int>(n, -1);
        return min(solve(n-1), solve(n-2));
    }
};
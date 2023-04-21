class Solution {
    int n;
    // vector<int>costList;
    vector<int>dp;
//     int solve(int i){
//         if(i == 0 or i == 1) return costList[i];
            
        
//         if(dp[i]!=-1) return dp[i];
        
//         return dp[i] = costList[i] + min(solve(i-1), solve(i-2));
    
//     }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        // costList = cost;
        dp = vector<int>(n, 0);
        dp[0] = cost[0]; dp[1] = cost[1];
        
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
        // return min(solve(n-1), solve(n-2));
    }
};
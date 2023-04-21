class Solution {
    int minP;
    int members;
    vector<int>groupList;
    vector<int>profitList;
    vector<vector<vector<int>>>dp;
    #define MOD 1000000007
    int dfs(int i, int members, int profitAchieved){
        if(members<0) return 0;
        
        if(i >= groupList.size())
            return profitAchieved>=minP?1:0;
            
        if(dp[i][members][profitAchieved]!=-1) return dp[i][members][profitAchieved];
        
        //skipping
        dp[i][members][profitAchieved] = dfs(i+1, members, profitAchieved)%MOD;
            
        //not skipping 
        if(members - groupList[i]>=0)
            dp[i][members][profitAchieved] += dfs(i+1, members - groupList[i], min(profitAchieved + profitList[i], minP))%MOD;
        
        return dp[i][members][profitAchieved]%MOD;
    }
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        members = n;
        minP = minProfit;
        groupList = group;
        profitList = profit;
        dp = vector<vector<vector<int>>>(102, vector<vector<int>>(102, vector<int>(102, -1)));
        return dfs(0, members, 0);
        
    }
};
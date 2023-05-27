class Solution {
    int n;
    vector<int> stoneValues;
    vector<int> memo;
    
    int dfs(int i) {
        if (i >= n) return 0;
        
        if (memo[i] != INT_MIN) return memo[i];
        
        int res = INT_MIN;
        int sum = 0;
        
        for (int j = 0; j < 3 && i + j < n; j++) {
            sum += stoneValues[i + j];
            res = max(res, sum - dfs(i + j + 1));
        }
        
        memo[i] = res;
        
        return res;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        stoneValues = stoneValue;
        memo.resize(n, INT_MIN);
        
        int score = dfs(0);
        
        if (score > 0) return "Alice";
        else if (score < 0) return "Bob";
        else return "Tie";
    }
};

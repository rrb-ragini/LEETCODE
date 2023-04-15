class Solution {
    vector<vector<int>>pile;
    int col;
    int n;
    vector<vector<int>>coin;
    // int maxi=INT_MIN;
    int dp(int idx, int k){
//         for(int i = 1; i <= n; i++){
//             int pileSize = pile[i-1].size();
//             for(int j = 1;  j <= col; j++){
//                 int sum = 0;
                
//                 for(int k=0;k<pileSize;k++)
//                 {
//                     if((k+1)>j)break;
//                     sum+=pile[i-1][k];
//                     coin[i][j] = max({coin[i][j],sum+coin[i-1][j-(k+1)],coin[i-1][j]});
//                     maxi = max(maxi,coin[i][j]);
//                 }
//                 }
//             }
        
        if(idx==n) return 0;
        
        if(coin[idx][k]) return coin[idx][k];
        
        int not_taken = dp(idx+1, k);
        
        int taken = 0, sum = 0;
        for(int j = 0; j < min((int)pile[idx].size(), k); j++){
            sum += pile[idx][j];
            taken = max(taken, sum + dp(idx+1, k - (j+1)));
            }
        
        return coin[idx][k] = max(taken, not_taken);
        
        }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        pile = piles; 
        col = k;
        coin = vector<vector<int>>(n+1, vector<int>(k+1, 0));
        
        return dp(0, k);
    }
};

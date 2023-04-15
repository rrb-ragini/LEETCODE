class Solution {
    vector<vector<int>>pile;
    int col;
    int n;
    vector<vector<int>>coin;
    int maxi=INT_MIN;
    void dp(){
        for(int i = 1; i <= n; i++){
            int pileSize = pile[i-1].size();
            for(int j = 1;  j <= col; j++){
                int sum = 0;
                
                for(int k=0;k<pileSize;k++)
                {
                    if((k+1)>j)break;
                    sum+=pile[i-1][k];
                    coin[i][j] = max({coin[i][j],sum+coin[i-1][j-(k+1)],coin[i-1][j]});
                    maxi = max(maxi,coin[i][j]);
                }
                }
            }
        }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        pile = piles; 
        col = k;
        coin = vector<vector<int>>(n+1, vector<int>(k+1, 0));
        dp();
        return coin[n][k];
    }
};

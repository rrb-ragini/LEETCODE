class Solution {
    int n = 0, m = 0;
    vector<vector<bool>>visited;
    int count = 0;
    vector<vector<char>>grid;
    
    void dfs(int i, int j){
        if(i <0 or i > n-1 or j < 0 or j > m-1) return;
        if(visited[i][j] == true or grid[i][j] == '0') return;
        
        visited[i][j] = true;
        
        if(grid[i][j] == '1' ){
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j-1);
            dfs(i, j+1);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();
        
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]=='1' and visited[i][j]!=true){
                    count++;                    
                    dfs(i, j);
                }
        
        return count;
    }
};
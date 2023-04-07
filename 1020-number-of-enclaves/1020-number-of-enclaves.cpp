class Solution {
    int m, n;
    vector<vector<int>>g;
    vector<vector<bool>>visited;
    long long count = 0;
    int res = 0; 
    int section = 0; 
    
    int dfs(int row, int col){
        if(row<0 or col<0) return 0;
        if(row >=m or col >= n) return 0;
        if(visited[row][col] == true or g[row][col]==0) return 1;
        
        visited[row][col] = true; //visited criteria
        
        section = min(dfs(row+1, col), min(dfs(row-1, col), min(dfs(row, col+1), dfs(row, col-1))));
        if(section==0) res=0; else res++;
        return res;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        m = grid.size();
        n = grid[0].size();
        g = grid; 
        
        visited = vector<vector<bool>>(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(visited[i][j]==false and g[i][j]==1){
                    count+=dfs(i, j);
                    res = 0;
                }
                
        return count;
    }
};
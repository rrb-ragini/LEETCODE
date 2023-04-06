class Solution {
    vector<vector<bool>>visited;
    int count = 0; 
    int m, n;
    vector<vector<int>>g;
    int dfs(int row, int col){
        if(row < 0 or col < 0) return 0; 
        if(row>=m or col>= n) return 0; 
        if(visited[row][col] or g[row][col] == 1) return 1;
        
        visited[row][col] = 1; 
        // int mini = min(dfs(row+1, col, grid), dfs(row-1, col, grid), dfs(row, col+1, grid), dfs(row, col-1, grid));
        int mini = min(dfs(row+1, col), min(dfs(row-1, col), min(dfs(row,col+1), dfs(row, col-1))));
        return mini;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid; 
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j] and !visited[i][j])
                    count+= dfs(i, j);
            }
        }
        return count; 
    }
};
class Solution {
    int n = 0, m = 0;
    vector<vector<bool>>visited;
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int a){
            if(image[sr][sc] == a){
                image[sr][sc] = color; 
                if(sr>=1) fill(image, sr-1, sc, color, a);
                if(sc>=1) fill(image, sr, sc-1, color, a);
                if(sr<n-1) fill(image, sr+1, sc, color, a);
                if(sc<m-1) fill(image, sr, sc+1, color, a);
            }
        }
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int a = image[sr][sc];
        
        if(color !=a)
            fill(image, sr, sc, color, a);
        return image;
    }
};
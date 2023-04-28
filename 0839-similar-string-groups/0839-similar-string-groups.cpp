class Solution {
    int n, m;
    bool *visited = NULL;
    vector<string> strs;
    
    bool isSimilar(int i, int j){
        int count = 0;
        for(int k = 0; k < m; k++)
            if(strs[i][k]!=strs[j][k])
                count++;
        return (count == 0 or count == 2);
    }
    
    void dfs(int i){
        if(visited[i]) return;
        visited[i] = true;
        
        for(int j = 0; j < n; j++)
            if(isSimilar(i, j))
                dfs(j);        
    }
public:
    int numSimilarGroups(vector<string>& str) {
        strs = str;
        n = strs.size();
        m = strs[0].size();
        visited = new bool[n]{};
        int res = 0;
        
        //dfs
        for(int i = 0; i < n; i++)
            if(!visited[i]){
                dfs(i);
                res++;
            }
        
        return res;
    }
};
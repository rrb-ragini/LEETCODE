class Solution {
    
    void dfs(map<int, vector<int>>&graph, vector<int>&visited, int i, vector<int>&v){
        if(visited[i]) return;
        
        visited[i] = 1;
        
        v.push_back(i);
        
        for(auto e:graph[i]){
            if(visited[e] == 0)
                dfs(graph, visited, e, v);
        }
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>>graph;
        
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int>visited(n, 0);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 1) continue;
            
            vector<int>v;
            
            dfs(graph, visited, i, v);
            
            int edge = 0;
            
            for(auto i:v){
                edge += graph[i].size();
            }
            
            int s = v.size();

            if(edge >= s*(s-1)) ans++;
             
        }
        
        return ans;
        
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // dfs, vvector visited, if visited == 0, include in ans vector 
        vector<int>indegree(n, 0);
        
        for(auto e:edges)
            indegree[e[1]]++;
//      0 1 2 3 4 5
//        T T   T  T 
        vector<int>ans;
        for(int i = 0; i < n; i++)
            if(!indegree[i]) ans.push_back(i);
        return ans;
    }
};
class Solution {
    // unordered_map<string, int>mp;
    vector<vector<int>>visited;    
    int lcs(string text1, string text2, int n1, int n2){
        if(n1 == 0 or n2 == 0) return 0;
        
//         // string key  = to_string(n1) + '|' + to_string(n2);
//         if(visited[n1][n2]!=-1) return visited[n1][n2];
//         // if(mp.find(key)!=mp.end()) return mp[key];
        
//         if(text1[n1-1] == text2[n2-1]) visited[n1][n2] = 1 + lcs(text1, text2, n1-1, n2-1);
//         else visited[n1][n2] = max(lcs(text1, text2, n1, n2-1), lcs(text1, text2, n1-1, n2));
        
//         return visited[n1][n2];
        for(int i =1; i < n1 +1; i++){
            for(int j = 1; j  < n2+1; j++){
                if(text1[i-1]==text2[j-1]) visited[i][j] += visited[i-1][j-1] + 1;
                else visited[i][j] = max(visited[i][j-1], visited[i-1][j]);
            }
        }
        return visited[n1][n2];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        visited = vector<vector<int>>(n1 +1, vector<int>(n2 +1 , 0));
        int res = lcs(text1, text2, n1, n2);
        
        return res;
    }
};
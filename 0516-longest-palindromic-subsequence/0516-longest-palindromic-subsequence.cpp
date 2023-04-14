class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>visited(n+1, vector<int>(n+1, 0));
        string t = string(s.rbegin(), s.rend());
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <=n; j++){
                if(s[i-1] == t[j-1])
                    visited[i][j] +=visited[i-1][j-1] + 1;
                else visited[i][j] = max(visited[i-1][j], visited[i][j-1]);
            }
        
        return visited[n][n];
    }
};
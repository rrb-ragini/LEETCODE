class Solution {
    int n;
//     vector<vector<int>> question;
//     int solve(int i){
//         if(i >= n)  return 0;

//         //doing question and skipping i question
//         int countDo = question[i][0] + solve(i + question[i][1] + 1);

//         //skipping question
//         int countSkip = solve(i + 1);
        
//         //returning maximum of both
//         return max(countSkip, countDo);
//     }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // question = questions;
        n = questions.size();
        vector<long long>v(n, 0);
        // int count = solve(0);
        
        v[n-1] = questions[n-1][0];
        for(int i = n - 2; i >= 0; --i){
            v[i] = questions[i][0];
            
            if(i + questions[i][1] + 1 < n)
                // for(int j = i + questions[i][1] + 1; j < n; j++)
                    v[i] += v[i + questions[i][1] + 1];
            
            v[i] = max(v[i+1], v[i]);
        }        
        return v[0];
        // return count;
    }
};
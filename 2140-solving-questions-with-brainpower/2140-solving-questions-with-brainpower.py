class Solution(object):
    def mostPoints(self, questions):
        """
        :type questions: List[List[int]]
        :rtype: int
        """
        n = len(questions)
        v = [0] * n

        def solve(i):
            if i >= n: return 0
                    
            if v[i]: return v[i]
            
            count = questions[i][0] + solve(i+1 + questions[i][1])
            
            skip = solve(i+1)
            
            v[i] = max(count, skip)
            return v[i]
        
        return solve(0)
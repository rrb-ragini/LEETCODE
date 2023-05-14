class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += mat[i][i];
        
        for(int j = n-1; j >= 0; --j)
            sum += mat[n-1-j][j];

        if(n % 2 == 1)
            sum -= mat[n/2][n/2];
    
        return sum;
    }
}
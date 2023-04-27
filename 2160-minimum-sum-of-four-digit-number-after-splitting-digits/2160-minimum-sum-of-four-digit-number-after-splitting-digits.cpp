class Solution {
public:
    int minimumSum(int num) {
        vector<int>v(4, 0);
        
        v[3] = num%10;
        num = num/10;
        v[2] = num%10;
        num = num/10;
        v[1] = num%10;
        num = num/10;
        v[0] = num%10;
        sort(v.begin(), v.end());
        
        cout << v[0] << v[1] << v[2] << v[3] << endl;
        
        int a = v[2] + v[3];
        int b = v[0] + v[1] + a/10;
        return b*10 + a%10;
    }
};
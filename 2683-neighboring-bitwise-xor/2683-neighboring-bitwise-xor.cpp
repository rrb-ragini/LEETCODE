class Solution {
        
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool counter = true;
        int arr[n];
        arr[0] = 0;
        for(int i = 1; i <= n-1; i++){
            arr[i] = arr[i-1] ^ derived[i-1];
        }
        
        // for(int i = 0; i < n; i++)
        if(arr[n-1]^arr[0] != derived[n-1]) return false;

        
//         for(int i = 0; i < n - 1; i++)
//             if(derived[i]^derived[i+1] != derived[i]) return false;        
        
        return true;
    }
};
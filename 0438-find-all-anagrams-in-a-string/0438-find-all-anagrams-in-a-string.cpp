class Solution {
    vector<int>v;
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(); //10
        int m = p.length();//3
        vector<int>result;
        if(m > n) return result; //no
//         // mp<int, chat>mp;
//         // for(int i = 0; i < n; i++){
//         //     mp[i] = s[i];
//         // }
//         // auto itr =  mp.find
        
//         sort(p.begin(), p.end());
//         for(int i = 0; i <= n - m; i++){
//             string temp = s.substr(i, m);
//             sort(temp.begin(), temp.end());
//             if(temp == p) v.push_back(i);
//         }
//         return v;
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        for(int i = 0; i < m; i++){
            pCount[p[i] - 'a']++; // 1 1 1
            sCount[s[i] - 'a']++; // 1 1 1
        }
        
        int l = 0, r = m - 1; //r = 2

        while(l <= n - m){  
            cout << l << endl;
            if(sCount == pCount) result.push_back(l);
                        
            sCount[s[l] - 'a']--; 
            l++;
            
            r++;
            if(r < n)
                sCount[s[r] - 'a']++;
        }
        return result;
    }
};
class Solution {
    stack<char>sk;
public:
    string removeStars(string s) {
        for(auto i:s){
            if(i!='*') sk.push(i);
            else sk.pop();
        }
        int a = sk.size();

        string res(a,' ');

        for(int i = a-1; i >=0; i--){
            res[i]=sk.top();
            sk.pop();
        }
        return res;
    }
};
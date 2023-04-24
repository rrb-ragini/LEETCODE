class Solution {
    stack<char>st;
    stack<char>tt;
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#' and !st.empty())
                st.pop();
            else if(s[i]!='#') 
                st.push(s[i]);
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#' and !tt.empty())
                tt.pop();
            else if(t[i]!='#')
                    tt.push(t[i]);
        }
        cout << st.size() << tt.size() << endl;
        while(!st.empty() and !tt.empty()){
            if(st.top()!=tt.top()) return false;
            st.pop();
            tt.pop();
        }
        cout << "reached" << st.empty() << tt.empty();
        return st.empty() and tt.empty();
    }
};
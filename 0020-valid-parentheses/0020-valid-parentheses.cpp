class Solution {
    stack<char>p;
public:
    bool isValid(string s) {
        for(char c:s){
            if(c=='(' or c=='{' or c == '[') p.push(c);
            else if(c==')'){
                if(p.empty()==true) return false;
                if(p.top()=='(') p.pop(); else return false; 
            }
            else if(c=='}'){
                if(p.empty()==true) return false;
                if(p.top()=='{') p.pop(); else return false;
            }
            else if(c==']'){
                if(p.empty()==true) return false;
                if(p.top()=='[') p.pop(); else return false;
            }
        }
        if(p.empty()==true) return true;
        return false;
    }
};
class Solution {
public:
    bool isValid(string str) {
        auto IsOpen = [&](char  ch){
            return (ch == '(' || ch == '[' || ch == '{');
        };
        stack<char>s;
        for(char ch : str){
            if(IsOpen(ch))s.push(ch);
            else{
                if(s.empty())return false;
                else if(s.top() == '(' && ch == ')' || s.top() == '[' && ch == ']' || s.top() == '{' && ch == '}')s.pop();
                else return false;
            }

        }
        return s.empty();
    }
};
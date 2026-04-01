class Solution {
public:
    int evaluate(int V1 , int V2, string exp){
        if(exp == "+")return V1+V2;
        if(exp == "/")return V1/V2;
        if(exp == "*")return V1*V2;
        if(exp == "-")return V1-V2;
        return -1;
    }
    bool exp(string s ){
        vector<string>str = {"+" , "-" , "/" , "*"};
        for(auto st : str)if(st == s)return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {

        stack<int>val;
        for(auto ch : tokens){
            if(exp(ch)){
                int V2 = val.top(); val.pop();
                int V1 = val.top() ; val.pop();
                int result = evaluate(V1 , V2 , ch);
                val.push(result);
            }
            else{
                val.push(stoi(ch));
            }
        }
        return val.top();
    }
};
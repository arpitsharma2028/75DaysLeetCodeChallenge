class Solution {
public:
    bool f(char c){
        if(c >= 'A' && c <= 'Z' || c>= 'a' && c<= 'z' || c>= '0' && c<= '9')return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0 , r = n-1;
        vector<char>vec(n,' ');
        while(l<r){
            while(l<r && !f(s[l]))l++;
            while(l<r && !f(s[r]))r--;

             if(s[l]>= 'A' && s[l]<= 'Z')s[l] = tolower(s[l]);
             if(s[r]>= 'A' && s[r]<= 'Z')s[r] = tolower(s[r]);

            
            if(tolower(s[l]) != tolower(s[r]))return false;
            vec[l] = tolower(s[l]);
            vec[r] = tolower(s[r]);
            l++;
            r--;
        }
        return true;
    }
};
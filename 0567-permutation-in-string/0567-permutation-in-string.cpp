class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0} , freq2[26] = {0};
        for(char s : s1)freq1[s-'a']++;
       // fixed size sliding window
        int l = 0 , Winsize = s1.size();
        for(int r = 0 ; r < s2.size() ; r++){
            freq2[s2[r] - 'a']++ ;
            while(r-l+1 > Winsize && l < r){
                freq2[s2[l]- 'a']-- ;
                l++;
            }
            bool res = true;
            for(int i = 0 ; i < 26 ; i++){
                if(freq1[i] != freq2[i]){
                    res = false;
                    break;
                }
            }
            if(res)return true;
        }
        return false;
    }
};
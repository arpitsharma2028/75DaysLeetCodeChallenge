class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26]={0};
        int ans = 0 , l = 0 , maxFreq = 0;
        for(int i = 0 ; i < s.size(); i++){
            int currIdx = s[i]-'A';
            hash[currIdx]++;
            maxFreq = max(maxFreq , hash[currIdx]);
            int currReq = (i-l+1) - maxFreq;
            if(currReq > k){
                hash[s[l]-'A']--;
                //maxFreq = 0;
                //for(int k = 0 ; k < 26 ; k++)maxFreq = max(maxFreq , hash[k]);
                l++;
            }
            currReq = (i-l+1) - maxFreq;
            if(currReq <=  k)
                ans = max(i-l+1 , ans);
            }      
        return ans;
    }
};
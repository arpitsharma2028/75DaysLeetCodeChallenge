class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>s;
        int n = nums2.size();
        vector<int>NGE(n , -1);
        for(int i = n-1 ; i >= 0  ; i--){
            while(!s.empty() && nums2[i] >= s.top())s.pop();
            if(!s.empty())mp[nums2[i]] = NGE[i] = s.top();

            s.push(nums2[i]);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            if(mp.find(nums1[i]) != mp.end())nums1[i] = mp[nums1[i]];
            else nums1[i] = -1;
        }
        return nums1;
    }
};
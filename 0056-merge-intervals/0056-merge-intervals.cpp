class Solution {
public:

    /*
        key idea:
        i know logic for overlapping intervals;
        if any intervals starts before ending of my previous interval => merge
        now problem is how can i implement this one line solution.

        And inputs must be sorted on basis of starting time.
        
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        int i=0;
        while(i<n){
            int st = intervals[i][0] , end = intervals[i][1];
            int j = i+1;
            while(j<n && intervals[j][0] <= end){
                st = min(st,intervals[j][0]);
                end = max(end , intervals[j][1]);
                j++;
            }
            ans.push_back({st,end});
            i = j;
        }
        return ans;

    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int res = 0, j = 0; 
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[j][1]) { 
                if (intervals[i][1] < intervals[j][1]) 
                    j = i;
                res++;
            }
            else {
                j = i; 
            }
        }
        return res;
    }
};

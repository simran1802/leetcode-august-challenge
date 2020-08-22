class Solution {
public:
    int index;
    int x, y;
    vector<vector<int>> rect;
    Solution(vector<vector<int>>& rects) {
        for(int i=0;i<rects.size();i++){
            if(rects.size()!=0) rect.push_back(rects[i]);
        }
        index = 0;
        x = min(rect[index][0], rect[index][2]);
        y = min(rect[index][1], rect[index][3]);
    }
    
    vector<int> pick() {
        vector<int> ans{x, y};
        int ye = max(rect[index][1], rect[index][3]);
        int xe = max(rect[index][0], rect[index][2]);
        if(ye>y) y++;
        else if(xe>x) {x++; y = min(rect[index][1], rect[index][3]);}
        else{
            index++;
            index%=rect.size();
            x = min(rect[index][0], rect[index][2]);
            y = min(rect[index][1], rect[index][3]); 
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

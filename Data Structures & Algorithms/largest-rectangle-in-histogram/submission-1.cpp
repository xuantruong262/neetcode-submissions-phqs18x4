class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        set<int> S_Leng(heights.begin(), heights.end());
        int max_area = *S_Leng.rbegin();
        int w = 0;
        int Min2MaxH = 0;
        for (int h : S_Leng) {
            for (int i = 0; i < heights.size(); i++) {
                if (heights[i] >= h) {
                    w++;
                }
                else {
                    max_area = max(max_area, w * h);
                    w = 0;
                }

            }
            if (w > 0) {
                max_area = max(max_area, w * h);
                w = 0;
            }
        }

        return max_area;
    }
};

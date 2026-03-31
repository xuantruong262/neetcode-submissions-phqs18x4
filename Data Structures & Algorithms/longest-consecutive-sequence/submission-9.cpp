class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> buf;
        if (nums.size() == 0) return 0;
        vector<int> s_vec;
        for (int i : nums) {
            buf.insert(i);
        }
        for (auto it = buf.begin(); it != buf.end(); ++it) {
            s_vec.push_back(*it);
        }
        int count = 1;
        int max = 0;
        max = (count > max) ? count : max;
        for (int i = 0; i < s_vec.size() - 1;i++) {
            int cur_v = s_vec[i];
            int nex_v = s_vec[i+1];
            if (nex_v == (cur_v + 1)) {
                count++;
            }
            else {
                max = (count > max) ? count : max;
                count = 1;
            }
        }
        max = (count > max) ? count : max;
        return max;
    }
};

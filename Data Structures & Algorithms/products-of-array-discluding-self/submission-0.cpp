class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> shadow_nums;
        vector<int> output;
        int total = 1;
        for (int i = 0; i < nums.size(); ++i) {
            shadow_nums = nums;
            shadow_nums[i] = 1;
            for (int a: shadow_nums) {
                total *= a;
            }
            output.push_back(total);
            total = 1;
        }
        return output;
    }
};

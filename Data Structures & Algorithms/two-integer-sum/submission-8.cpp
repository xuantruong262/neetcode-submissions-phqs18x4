class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for(int num = 0; num < nums.size() ;++num){
            for(int sub_num = num+1; sub_num < nums.size();++sub_num){
                if(nums.at(num) + nums.at(sub_num) == target)
                {
                    output.push_back(num);
                    output.push_back(sub_num);
                }
            }
        }
        return output;
    }
};

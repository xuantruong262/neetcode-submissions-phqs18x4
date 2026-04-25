class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int a = 0;
        while(l <= r){
            a = l + (r-l)/2;
            if(target > nums[a]){
                l = a + 1;
            }
            else if(target < nums[a]){
                r = a - 1;
            }
            else{
                return a;
            }
        }
        return - 1;
    }
};

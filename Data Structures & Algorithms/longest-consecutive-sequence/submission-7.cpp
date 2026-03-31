vector<int> Duplicate_Arrangment(vector<int> &need_check) {
    unordered_set<int> checker;
    vector<int> out;
    for (int i : need_check) {
        if (checker.count(i)) {
            continue;
        };
        checker.insert(i);
    }
    
    for (int i : checker) {
        out.push_back(i);
    }
    sort(out.begin(), out.end());
    return out;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_cons = 0;
        int consecutive_cnt = 1;
        vector<int> tmp;
        vector<int> output;
        tmp = Duplicate_Arrangment(nums);
        int prev_num = 0;
        if (!tmp.size()) {
            return 0;
        }
        for (int i = 0; i < tmp.size(); i++) {
            if (!i) {
                prev_num = tmp.at(i);
                continue;
            }
            if ((tmp.at(i) - prev_num) == 1) {
                consecutive_cnt++;
            }
            else {
                if (consecutive_cnt >= longest_cons) {
                    longest_cons = consecutive_cnt;
                }          
                consecutive_cnt = 1;      
            }
            prev_num = tmp.at(i);
        }

        return (consecutive_cnt > longest_cons) ? consecutive_cnt : longest_cons;
    }
};

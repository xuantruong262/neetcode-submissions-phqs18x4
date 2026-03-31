class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> s;
        map<int, int> s2;
        for (int i : nums) {
            s[i]++;
        }
        while (k > 0) {
            int max_k = 0;
            int max_v = 0;
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (it->second > max_v) {
                    max_v = it->second;
                    max_k = it->first;
                }
            }

            res.push_back(max_k);
            s[max_k] = 0;
            k--;
        }

        return res;
    }
};

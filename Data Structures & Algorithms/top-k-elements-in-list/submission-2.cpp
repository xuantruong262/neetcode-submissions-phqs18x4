int idx[10000];
int sum[10000];

int sort_arr(unordered_map<int, int> &t) {
    int i = 0;
    for (auto it = t.begin(); it != t.end(); ++it) {
        idx[i] = it->first;
        sum[i] = it->second;
        i++;
    }
    int temp_idx = 0;
    int temp_sum = 0;
    // sort array index
    for (int j = 0, k = 0; j < i; j++) {
        k = j;
        while (k < i) {
            if (sum[k] >= sum[j]) {
                temp_sum = sum[j];
                temp_idx = idx[j];
                sum[j] = sum[k];
                idx[j] = idx[k];
                sum[k] = temp_sum;
                idx[k] = temp_idx;
            }
            k++;
        }
    }
    return i;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> top_key;
        unordered_map<int,int> temp;
        unordered_map<int, int> temp2;
        int biggest_val = 0;
        vector<int> checker;
        int rq_cnt = 0;
        for (int u : nums) {
            temp[u]++;
        }
        sort_arr(temp);
        for (int m = 0; m < k; ++m) {
            top_key.push_back(idx[m]);
        }
        return top_key;
    }
};

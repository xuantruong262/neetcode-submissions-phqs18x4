class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> day_temp; //{day, temp}
        int T = 0;
        for (int i = 0; i < temperatures.size(); i++) {
            T = temperatures[i];
            while (!day_temp.empty() && (T > day_temp.top().second)) {
                pair<int,int> A = day_temp.top();
                day_temp.pop();
                res[A.first] = i - A.first;
            }
            day_temp.push({ i,T });
        }
        return res;
    }
};

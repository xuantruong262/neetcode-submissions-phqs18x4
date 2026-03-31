class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> i_Cars;
        stack<double> res;
        for (int p = 0; p < position.size(); p++) {
            i_Cars.push_back({ position[p],speed[p] });
        }
        sort(i_Cars.rbegin(), i_Cars.rend());
        double Time = 0;
        for (auto p : i_Cars) {
            Time = (double)(target - p.first) / p.second; //cal time

            if (!res.empty() && Time <= res.top()) {
                
            }
            else {
               res.push(Time);
            }
        }
        return res.size();
    }
};

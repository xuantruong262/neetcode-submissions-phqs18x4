    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int ascii_arr[26] = {0};
    
        for(char c:s){
            ascii_arr[c - 'a']++;
        }
        for(char c:t){
            ascii_arr[c - 'a']--;
        }

        for(int i: ascii_arr){
            if(ascii_arr[i] !=0) return false;
        }
        return true;
    }

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> m_groupAnagrams;
        vector<string> sub_group;
        // Get total ascii number
        vector<int> sub_group_in_dec;
        int cnt = 0;
        while (strs.size())
        {
            string org = strs.at(0);
            sub_group.push_back(org);
            strs.erase(strs.begin());

            for (int i = 0; i < strs.size();) {
                string child = strs.at(i);
                if (isAnagram(org,child)) {
                    sub_group.push_back(strs.at(i));
                    strs.erase(strs.begin() + i);
                    continue;
                }
                i++;
            }
            
            m_groupAnagrams.push_back(sub_group);
            sub_group.clear();
        }
        return m_groupAnagrams;
    }
};

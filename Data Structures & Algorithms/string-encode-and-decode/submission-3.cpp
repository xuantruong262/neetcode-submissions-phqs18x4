class Solution {
public:
    string encode(vector<string>& strs) {
        int string_length = 0;
        string out_string;
        for (string s_string : strs) {
            string_length = s_string.length();
            out_string = out_string + to_string(string_length) + "#" + s_string;
        }
        return out_string;
    }
    vector<string> decode(string s) {
        string ref_s = s;
        bool key_lock = false;
        string s_string;
        vector<string> out_vector_string;
        int total_num_of_string = 0;
        int num_of_char = 0;
        for (int i = 0; i < ref_s.length();i++) {
            if (total_num_of_string == 0) {
                total_num_of_string = ref_s.find_first_of("#");
                string num_str;
                for (int j = 0; j < total_num_of_string; j++) {
                    num_str += ref_s[j];
                }
                num_of_char = atoi(num_str.c_str());
                ref_s = ref_s.substr(total_num_of_string+1);
                if (num_of_char == 0) {
                    i = -1;
                    out_vector_string.push_back(s_string);
                    total_num_of_string = 0;
                    continue;
                }
            }
            // Process string filter
            
            s_string = s_string + ref_s.at(i);
            num_of_char--;
            
            if (num_of_char == 0) {
                out_vector_string.push_back(s_string);
                ref_s = ref_s.substr(s_string.length());
                s_string.clear();
                total_num_of_string = 0;
                i = -1;
            }
        }
        return out_vector_string;
    }

};

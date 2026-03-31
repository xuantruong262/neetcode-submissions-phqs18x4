bool Check_duplicate(vector<int> & need_check) {
    unordered_set<int> checker;
    for (int i : need_check) {
        if (checker.count(i)) {
            return true;
        };
        checker.insert(i);
    }
    return false;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> c2i;
        char c;
        // Check row
        for (vector<char> row : board) {
            // Convert
            for (char element : row) {
                int A = atoi(&element);
                if (A == 0) {
                    continue;
                }
                else {
                    c2i.push_back(A);
                };
            }
            if(Check_duplicate(c2i) == true)
            {
                return false;
            }
            c2i.clear();
        }
        // Check col
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                c = (char)board.at(j)[i];
                int A = atoi(&c);
                if (A == 0) {
                    continue;
                }
                else {
                    c2i.push_back(A);
                };
            }
            if (Check_duplicate(c2i) == true)
            {
                return false;
            }
            c2i.clear();
        }
        c2i.clear();
        uint8_t B = 0;
        // Check 3x3 block
        for (int row = 0; row < 9; row +=3) {
            for (int col = 0; col < 9; col += 3) {
                for (int sub_row = (0+row) ; sub_row < row+3; sub_row++) {
                    c = (char)board.at(sub_row).at(col + 0);
                    B = atoi(&c);
                    if (B != 0) {
                        c2i.push_back(B);
                    }
                }
                for (int sub_row = (0 + row); sub_row < row + 3; sub_row++) {
                    c = (char)board.at(sub_row).at(col + 1);
                    B = atoi(&c);
                    if (B != 0) {
                        c2i.push_back(B);
                    }
                }
                for (int sub_row = (0 + row); sub_row < row + 3; sub_row++) {
                    c = (char)board.at(sub_row).at(col + 2);
                    B = atoi(&c);
                    if (B != 0) {
                        c2i.push_back(B);
                    }
                }
                if (Check_duplicate(c2i) == true)
                {
                    return false;
                }
                c2i.clear();
            }

            
        }
        return true;
    }
};

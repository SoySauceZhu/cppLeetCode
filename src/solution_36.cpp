//
// Created by Mingjie.Zhu22 on 2025/11/7.
//

#include <iostream>
#include <set>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // row[i][d] 表示第 i 行是否出现过数字 d+1 (bit mask)
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue; // 只会有 '1'~'9' 或 '.'

                int d = c - '1'; // 数字映射到 0~8
                int b = (i / 3) * 3 + j / 3; // 第几个 box，0~8

                if (row[i][d] || col[j][d] || box[b][d]) {
                    // 行 / 列 / box 里已经出现过这个数字了
                    return false;
                }

                row[i][d] = col[j][d] = box[b][d] = true;
            }
        }
        return true;
    }

    bool isValidSudoku1(vector<vector<char> > &board) {
        // Check rows
        for (auto row: board) {
            set<char> curr_row;

            for (auto number: row) {
                /*
                set.find() return a iterator. you can use
                set.end() return a iterator points to the position of set.size().
                set.begin()
                set.rbegin()
                */
                if (!isdigit(number))
                    continue;

                auto res = curr_row.find(number);
                if (res != curr_row.end()) {
                    return false;
                }
                curr_row.insert(number);
            }

            curr_row.clear();
        }

        // Check column
        int n = board.size();
        for (int i = 0; i < n; i++) {
            set<char> curr_column;

            for (int j = 0; j < n; j++) {
                char number = board[j][i];
                if (!isdigit(number))
                    continue;

                if (curr_column.find(number) != curr_column.end()) {
                    return false;
                }
                curr_column.insert(number);
            }

            curr_column.clear();
        }

        // Check 3x3 sub-boxes

        for (int row = 0; row < n; row += 3) {
            for (int col = 0; col < n; col += 3) {
                set<char> curr_box;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char number = board[row + i][col + j];
                        if (!isdigit(number))
                            continue;

                        if (curr_box.find(number) != curr_box.end()) {
                            return false;
                        }

                        curr_box.insert(number);
                    }
                }

                curr_box.clear();
            }
        }

        return true;
    }
};


#include <vector>

int main() {
    Solution sol;

    std::vector<std::vector<char> > valid_board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    std::vector<std::vector<char> > invalid_board = valid_board;
    // introduce a duplicate '8' in first column to make it invalid
    invalid_board[0][0] = '8';

    std::cout << std::boolalpha;
    std::cout << "Valid board is valid: " << sol.isValidSudoku(valid_board) << '\n';
    std::cout << "Invalid board is valid: " << sol.isValidSudoku(invalid_board) << '\n';

    return 0;
}

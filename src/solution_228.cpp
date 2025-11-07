#include <iostream>
using namespace std;

class Solution {
public:
    string arr_string(int a, int b) {
        if (a == b) {
            return to_string(a);
        } else {
            return to_string(a) + "->" + to_string(b);
        }
    }


    vector<string> summaryRanges(vector<int> &nums) {


        vector<string> out;

        // Handle empty input
        if (nums.empty()) {
            return out;
        }

        int temp = nums[0];

        int i = 0;

        while (i < nums.size()) {
            if (i + 1 == nums.size()) {
                out.push_back(arr_string(temp, nums[i]));
                i++;
                continue;
            }

            if (nums[i] + 1 == nums[i + 1]) {
                i++;
                continue;
            } else {
                out.push_back(arr_string(temp, nums[i]));
                i++;
                temp = nums[i];
            }
        }
        return out;
    }
};


int main() {
    Solution sol;

    auto run = [&](const std::vector<int> &nums) {
        std::vector<int> input = nums;
        std::vector<std::string> out = sol.summaryRanges(input);

        std::cout << "Input: [";
        for (size_t i = 0; i < input.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << input[i];
        }
        std::cout << "] -> Output: [";
        for (size_t i = 0; i < out.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << out[i];
        }
        std::cout << "]\n";
    };

    run(std::vector<int>{});
    run(std::vector<int>{1});
    run(std::vector<int>{0, 1, 2, 4, 5, 7});
    run(std::vector<int>{-3, -2, -1, 1, 3, 4, 5, 7, 8, 9});

    return 0;
}

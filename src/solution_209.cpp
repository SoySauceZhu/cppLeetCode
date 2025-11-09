//
// Created by Mingjie.Zhu22 on 2025/11/7.
//
#include <iostream>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;              // left boundary of the window
        int sum = 0;               // current window sum
        int ans = INT_MAX;         // store the minimum length

        for (int right = 0; right < n; ++right) {
            sum += nums[right];    // expand window to the right

            // shrink from the left while sum is big enough
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};;


int main() {
    Solution sol;

    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    std::cout << "Test 1 (target=7) expected 2, got: " << sol.minSubArrayLen(7, nums1) << '\n';

    std::vector<int> nums2 = {1, 4, 4};
    std::cout << "Test 2 (target=4) expected 1, got: " << sol.minSubArrayLen(4, nums2) << '\n';

    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "Test 3 (target=11) expected 0, got: " << sol.minSubArrayLen(11, nums3) << '\n';

    return 0;
}

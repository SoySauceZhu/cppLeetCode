#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i++]);
            }
            else
            {
                temp.push_back(nums2[j++]);
            }
        }
        // if nums1 is longer
        while (i < m) temp.push_back(nums1[i++]);
        // if nums2 is longer
        while (j < n) temp.push_back(nums2[j++]);
        nums1 = temp;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    solution.merge(nums1, 3, nums2, 5);
    for (int i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

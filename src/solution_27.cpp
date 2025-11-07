/*
Parameter passing summary in C++:
---------------------------------
1. Pass by value (T v):
   - Makes a copy of the argument.
   - Safe but slower for large objects.
   - Modifications inside the function do NOT affect the caller.

2. Pass by reference (T& v):
   - No copy; directly refers to the caller's object.
   - Modifications affect the original object.
   - Cannot rebind to another object.

3. Pass by const reference (const T& v):
   - No copy; read-only access to the caller's object.
   - Recommended for large objects when no modification is needed.

4. Pass by pointer (T* v):
   - Passes the memory address.
   - Can be nullptr; can reassign to point elsewhere.
   - Requires explicit dereference (*v) to access.

5. Pass by rvalue reference (T&& v):
   - Binds to temporary (rvalue) objects.
   - Enables move semantics (efficient resource transfer).

Rule of thumb:
- Use `const T&` for read-only large objects.
- Use `T&` for in-place modification.
- Use `T*` only when nullptr or re-pointing is needed.
- Use `T&&` for move semantics.
- Use plain `T` for small, simple types (int, double, etc.).
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        std::vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                v.push_back(nums[i]);
            }
        }
        nums = v;
        return nums.size();
    }
};

// Test function to demonstrate the solution
void testRemoveElement() {
    Solution sol;
    
    // Test case 1: Normal case with multiple occurrences
    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    std::cout << "Test case 1:" << std::endl;
    std::cout << "Original array: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << std::endl;
    int k1 = sol.removeElement(nums1, val1);
    std::cout << "After removing " << val1 << ": ";
    for (int i = 0; i < k1; i++) std::cout << nums1[i] << " ";
    std::cout << std::endl;
    std::cout << "New length: " << k1 << std::endl;
    std::cout << std::endl;
    
    // Test case 2: All elements to be removed
    std::vector<int> nums2 = {1, 1, 1, 1};
    int val2 = 1;
    std::cout << "Test case 2:" << std::endl;
    std::cout << "Original array: ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << std::endl;
    int k2 = sol.removeElement(nums2, val2);
    std::cout << "After removing " << val2 << ": ";
    for (int i = 0; i < k2; i++) std::cout << nums2[i] << " ";
    std::cout << std::endl;
    std::cout << "New length: " << k2 << std::endl;
    std::cout << std::endl;
    
    // Test case 3: No elements to remove
    std::vector<int> nums3 = {4, 5, 6, 7};
    int val3 = 8;
    std::cout << "Test case 3:" << std::endl;
    std::cout << "Original array: ";
    for (int num : nums3) std::cout << num << " ";
    std::cout << std::endl;
    int k3 = sol.removeElement(nums3, val3);
    std::cout << "After removing " << val3 << ": ";
    for (int i = 0; i < k3; i++) std::cout << nums3[i] << " ";
    std::cout << std::endl;
    std::cout << "New length: " << k3 << std::endl;
    std::cout << std::endl;
    
    // Test case 4: Empty array
    std::vector<int> nums4 = {};
    int val4 = 1;
    std::cout << "Test case 4:" << std::endl;
    std::cout << "Original array: empty" << std::endl;
    int k4 = sol.removeElement(nums4, val4);
    std::cout << "After removing " << val4 << ": ";
    for (int i = 0; i < k4; i++) std::cout << nums4[i] << " ";
    std::cout << std::endl;
    std::cout << "New length: " << k4 << std::endl;
    std::cout << std::endl;
    
    // Test case 5: Mixed values
    std::vector<int> nums5 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val5 = 2;
    std::cout << "Test case 5:" << std::endl;
    std::cout << "Original array: ";
    for (int num : nums5) std::cout << num << " ";
    std::cout << std::endl;
    int k5 = sol.removeElement(nums5, val5);
    std::cout << "After removing " << val5 << ": ";
    for (int i = 0; i < k5; i++) std::cout << nums5[i] << " ";
    std::cout << std::endl;
    std::cout << "New length: " << k5 << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing LeetCode Problem 27: Remove Element" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::endl;
    
    testRemoveElement();
    
    std::cout << "All test cases completed!" << std::endl;
    return 0;
}

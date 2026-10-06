#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 1) return false;
        auto size = nums.size() - 1;
        std::unordered_map<int, int> map;
        for (int i = size; i >= 0; --i) {
            if (auto it = map.find(nums[i]); it != map.end() && (it->second - i) <= k) { // If number is already mapped
                return true;
            }
            // Insert / update num as key and index as value
            map[nums[i]] = i;
        }
        return false;
    }
};

int main () {
    Solution solution;

    // --- Test case 1 ---
    std::vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    bool result1 = solution.containsNearbyDuplicate(nums1, k1);
    std::cout << "Test case 1: " << (result1 ? "true" : "false") << std::endl; // Expected: true

    // --- Test case 2 ---
    std::vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    bool result2 = solution.containsNearbyDuplicate(nums2, k2);
    std::cout << "Test case 2: " << (result2 ? "true" : "false") << std::endl; // Expected: true

    // --- Test case 3 ---
    std::vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    bool result3 = solution.containsNearbyDuplicate(nums3, k3);
    std::cout << "Test case 3: " << (result3 ? "true" : "false") << std::endl; // Expected: false
}
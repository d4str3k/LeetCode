#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newLength = solution.removeElement(nums, val);
    
    // Output the new length and the modified array
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
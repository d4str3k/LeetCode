#include<vector>
#include<cassert>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate;
        auto votes{0};
        for (auto num: nums) {
            if (votes == 0) {
                candidate = num;
            }

            if (num == candidate) {
                votes++;
            } else {
                votes--;
            }
        }

        return (candidate);
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {3, 2, 3};
    int expected = 3;

    int result = s.majorityElement(nums);

    assert (result == expected);

    nums = {2, 2, 1, 1, 1, 2, 2};
    expected = 2;

    result = s.majorityElement(nums);

    assert (result == expected);
}
#include<vector>
#include<cassert>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        size_t write_ptr{1};
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[write_ptr] = nums[i];
                write_ptr++;
            }
        }
        return (write_ptr);
    }
};

int main()
{
    Solution s;

    std::vector<int> nums = {1, 1, 2};
    std::vector<int> expected = {1, 2};

    int k = s.removeDuplicates(nums);

    assert (k == expected.size());
    for (int i = 0; i < k; ++i) {
        assert (nums[i] == expected[i]);
    }

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    expected = {0, 1, 2, 3, 4};

    k = s.removeDuplicates(nums);

    assert (k == expected.size());
    for (int i = 0; i < k; ++i) {
        assert (nums[i] == expected[i]);
    }
}

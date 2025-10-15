// BUILD ARRAY FROM PERMUTATION
// 1 <= nums.length <= 1000
// 0 <= nums[i] < nums.length
// The elements in nums are distinct

#include <iostream>
#include <vector>

class Solution
{
public:

    std::vector<int> buildArray(std::vector<int>& nums)
    {
        std::vector<int> ans;

        for (int number : nums)
        {
            ans.push_back(nums[number]);
            std::cout << "number: " << number << "  nums[nums[number]] :" << nums[number] << std::endl;
        }
        return ans;
    }

};

int main()
{
    Solution test;

    std::vector<int> ans = {};
    std::vector<int> nums = {0, 2, 1, 5, 3, 4};

    ans = test.buildArray(nums);

    for (int n : ans) std::cout << n << ", ";

    return 0;
}
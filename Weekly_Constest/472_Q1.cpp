#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k)
    {
        int j = k;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == j) 
                j = j + k;
            else if (nums[i] > j && nums[i] % k == 0)
                return j;
        }
        return j;
    }
};

int main()
{
    Solution test;

    std::vector<int> nums = {8, 2, 3, 4, 6};
    int k = 2;
    
    std::cout << "Multiple: " << test.missingMultiple(nums, k) << std::endl;

    return 0;
}
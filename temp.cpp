#include <iostream>
#include <vector>
#include <algorithm>


void showVec(std::vector<int>& nums)
{
    //for (auto n : nums) std::cout << n;
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }
}

void organizeVec(std::vector<int>& nums)
{
    int temp = 0;

    int length = nums.size();

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }   
    }

    showVec(nums);
}


int main()
{
    std::vector<int> nums = {4, 3, 3, 2, 1};

    organizeVec(nums);

    for (int n : nums) std::cout << n << ", ";
    std::cout << std::endl;
   
    return 0;
}